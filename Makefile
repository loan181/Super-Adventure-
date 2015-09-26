SRC         :=  $(wildcard *.cpp)
OBJ         :=  $(patsubst %.cpp, obj/%.o, $(SRC))
DEP         :=  $(OBJ:.o=.d)
CPPFLAGS    :=  -MMD -MP
CXXFLAGS    :=  -std=c++11 -Wall -Wextra

SuperAdventure: $(OBJ)
	$(CXX) $^ -o $@

-include $(DEP)

clean:
	$(RM) $(OBJ) $(DEP)

obj/%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@