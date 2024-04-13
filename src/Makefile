.PHONY : install clean rebuild run

install: clean
	mkdir ../build
	cd ../build && cmake .. && make

rebuild:
	cd ../build && make && ./3dViewer

run:
	cd ../build && ./3dViewer

clean:
	rm -rf ../build