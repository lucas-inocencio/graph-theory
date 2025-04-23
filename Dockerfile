# Use an official C++ runtime as a parent image
FROM gcc:latest

# Set the working directory in the container to /lib
WORKDIR /app

# Copy the current directory contents into the container at /lib
COPY . /app

# Make port 80 available to the world outside this container
EXPOSE 80

# install cmake
RUN apt-get update && apt-get install -y cmake

# Run main.cpp when the container launches
CMD ["/bin/sh", "-c", "cmake . && make && ./main"]