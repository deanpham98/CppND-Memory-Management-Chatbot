.Phony: build
build:
		mkdir -p build
		cd build && \
		cmake .. && \
		make

.Phony: debug
debug:
		mkdir -p build
		cd build && \
		cmake -DCMAKE_BUILD_TYPE=debug .. && \
		make

.Phony: clean
clean:
		rm -rf build