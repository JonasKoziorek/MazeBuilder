run:
	@g++ SVG.cpp main.cpp DFS.cpp Grid.cpp Adlist.cpp -o program -fsanitize=address && ./program
	@echo "Finished."
