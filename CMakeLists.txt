cmake_minimum_required(VERSION 3.22)

project(graph-theory)

set(SOURCES
    main.cpp
	./src/linked-list/LinkedList.cpp
	./src/linked-list/LinkedListNode.cpp
	./src/representation/AdjacencyList.cpp
	./src/representation/AdjacencyMatrix.cpp
	./src/representation/IncidenceMatrix.cpp
)

set(HEADERS
	./include/LinkedList.hpp
	./include/LinkedListNode.hpp
	./include/AdjacencyList.hpp
	./include/AdjacencyMatrix.hpp
	./include/IncidenceMatrix.hpp
)

# Add executable target
add_executable(main ${SOURCES} ${HEADERS})