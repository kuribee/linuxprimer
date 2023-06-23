target=test
src=$(wildcard ./src/*.cpp)
obj=$(patsubst %.cpp,%.o,$(src))
cc=g++
lib_path=./lib
lib_src_path=./libSrc

$(target):$(obj)
	cd $(lib_src_path) && make && cd ../
	$(cc) $^ -L$(lib_path) -lsub -o $@

.PHONY:clean
clean:
	cd $(lib_src_path) && make clean && cd ../
	rm $(target) $(obj)