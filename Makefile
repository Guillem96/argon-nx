
.PHONY: all clean


all: directories primary gui
	$(MAKE) -C modules/minerva

directories:
	@mkdir -p output

gui:
	$(MAKE) -C argon-nx-gui

primary:
	$(MAKE) -C argon-first-stage

clean:
	$(MAKE) -C modules/minerva clean
	$(MAKE) -C argon-first-stage clean
	$(MAKE) -C argon-nx-gui clean
	rm -rf output/

dist: clean all 
	mkdir -p argon/logos
	mkdir -p argon/payloads
	mkdir -p argon/sys

	cp output/argon-nx.bin argon-nx.bin
	cp output/argon-nx-gui.bin argon/sys/argon-nx-gui.bin

	cp output/libsys_minerva.bso argon/sys/minerva.bso
	
	cp img/example-custom/logos/* argon/logos
	cp img/example-custom/backgrounds/default.bmp argon/background.bmp
	cp img/example-custom/splashes/default.bmp argon/splash.bmp
	
	cp modules/resources.argon argon/sys/resources.argon

	zip -r argon-nx.zip argon argon-nx.bin

	rm -rf argon
	rm argon-nx.bin