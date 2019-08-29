import click
from PIL import Image
from PIL import ImageDraw
from wand.image import Image as WI

import struct

def add_corners(im, rad):
    circle = Image.new('L', (rad * 2, rad * 2), 0)
    draw = ImageDraw.Draw(circle)
    draw.ellipse((0, 0, rad * 2, rad * 2), fill=255)
    alpha = Image.new('L', im.size, 255)
    w, h = im.size
    alpha.paste(circle.crop((0, 0, rad, rad)), (0, 0))
    alpha.paste(circle.crop((0, rad, rad, rad * 2)), (0, h - rad))
    alpha.paste(circle.crop((rad, 0, rad * 2, rad)), (w - rad, 0))
    alpha.paste(circle.crop((rad, rad, rad * 2, rad * 2)), (w - rad, h - rad))
    im.putalpha(alpha)
    return im


@click.group()
def main():
    pass

@main.command()
@click.argument('img-path', type=click.Path(exists=True, dir_okay=False))
@click.option('--round/--no-round', default=False, help="Round image corners?")
def img_to_logo(img_path, round):
    im = Image.open(img_path)
    im = im.resize((280, 280))
    if round:
        im = add_corners(im, 30)
    im.save('./out.png')

    with WI(filename='./out.png') as img:
        print(img.format)
        with img.convert('BMP') as i:
            i.save(filename='logo.bmp')

    
if __name__ == '__main__':
    main()