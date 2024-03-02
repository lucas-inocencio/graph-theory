# Use an official C++ runtime as a parent image
FROM gcc:latest

# Set the working directory in the container to /lib
WORKDIR /app

# Copy the current directory contents into the container at /lib
COPY . /app

# Make port 80 available to the world outside this container
EXPOSE 80

# Run main.cpp when the container launches
CMD ["cd build", "cmake ..", "make", "./main"]