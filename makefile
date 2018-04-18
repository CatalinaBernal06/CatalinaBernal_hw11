pos.png vel.png phase.png : tray.txt CB_graph.py
	python CB_graph.py

tray.txt : CB_gravity.cpp
	c++ CB_gravity.cpp -o grav
	./grav > tray.txt
