from pathlib import Path

import click
from PIL import Image
from PIL import ImageDraw
from wand.image import Image as WI


DST_PATH = 'sd-files/argon'

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


def to_bmp(img, size):
    img.resize(*size)
    img.alpha_channel = True
    return img.convert('BMP')


@click.group()
def main():
    pass


@main.command()
@click.argument('img-path', type=click.Path(exists=True, dir_okay=False))
@click.option('--round/--no-round', default=False, help="Round image corners?")
def img_to_logo(img_path, round):
    img_path = Path(img_path)
    img_name = img_path.stem
    fname = Path('{}.bmp'.format(img_name))
    out_path = str(logos_dst_path.joinpath(fname))

    # Preprocess image using pillow
    im = Image.open(img_path)
    im = im.resize((280, 280))
    im = im.convert('RGBA')

    if round:
        im = add_corners(im, 30)

    # Save image as a temp file
    im.save('./.tmp.png')

    # Reload image and convert it to 32 bmp bit format
    with WI(filename='./.tmp.png') as img:
        with img.convert('BMP') as i:
            i.save(filename=out_path)

    # Remove the tmp file
    Path('./.tmp.png').unlink()

    print('Convertion done. Check your new logo here: {}'.format(out_path))
    

@main.command()
@click.argument('img-path', type=click.Path(exists=True, dir_okay=False))
def generate_background(img_path):
    out_path = str(dst_path.joinpath('background.bmp'))
    with WI(filename=img_path) as img:
        im = to_bmp(img, (1280, 720))
        i.save(filename=out_path)

    print('Convertion done. Check your new background here: {}'.format(out_path))


@main.command()
@click.argument('img-path', type=click.Path(exists=True, dir_okay=False))
def generate_splash(img_path):
    out_path = str(dst_path.joinpath('splash.bmp'))
    with WI(filename=img_path) as img:
        im = to_bmp(img, (1280, 720))
        im.rotate(270)
        im.save(filename=out_path)

    print('Convertion done. Check your new splash here: {}'.format(out_path))
 
if __name__ == '__main__':
    dst_path = Path(DST_PATH)
    logos_dst_path = dst_path.joinpath('logos')
    logos_dst_path.mkdir(exist_ok=True, parents=True)

    main()