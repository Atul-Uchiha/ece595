default:
	cd makeprocs; make
	cd hello_world; make
	cd test2; make
	cd test3; make
	cd test4; make
	cd test6; make

clean:
	cd makeprocs; make clean
	cd hello_world; make clean
	cd test2; make clean
	cd test3; make clean
	cd test4; make clean
	cd test6; make clean

run:
	cd ../../bin; dlxsim -x os.dlx.obj -a -u makeprocs.dlx.obj; ee469_fixterminal

drun:
	cd ../../bin; dlxsim -D m -x os.dlx.obj -a -D m -u makeprocs.dlx.obj; ee469_fixterminal
