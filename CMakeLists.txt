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
	./src/linked-list/LinkedList.hpp
	./src/linked-list/LinkedListNode.hpp
	./src/representation/AdjacencyList.hpp
	./src/representation/AdjacencyMatrix.hpp
	./src/representation/IncidenceMatrix.hpp
)

# Add executable target
add_executable(main ${SOURCES} ${HEADERS})