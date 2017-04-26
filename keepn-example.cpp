/*
KeepNExample v1.5
Copyright(c) 2017 Steven Shave

Distributed under the MIT license

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "keepn.hpp"
#include <iostream>
#include <random>
#include <vector>
struct MyComplicatedDataStructure {
  int a;
  float b;
  std::vector<std::vector<int>> bigData;
  explicit MyComplicatedDataStructure(
      unsigned in_a, float in_b,
      const std::vector<std::vector<int>> in_bigData) {
    a = in_a;
    b = in_b;
    bigData = in_bigData;
  }
};

int main(int argc, char **argv) {
  std::random_device randdevice;
  std::default_random_engine engine(randdevice());
  std::uniform_int_distribution<int> uniform_dist(1, 1000);
  auto randint = [&uniform_dist, &engine]() { return uniform_dist(engine); };
  KeepNAscending<MyComplicatedDataStructure> keepasc(1000);
  KeepNDescending<MyComplicatedDataStructure> keepdesc(1000);
  for (int i = 0; i < 1000000; ++i) {
	  MyComplicatedDataStructure object(static_cast<int>(i), (randint()*1.0f),
                                      {{i, i + 1, i + 2, i + 3},
                                       {i, i + 1, i + 2, i + 3},
                                       {i, i + 1, i + 2, i + 3},
                                       {i, i + 1, i + 2, i + 3}});
    keepasc.insert(object, randint());
    keepdesc.insert(object, randint());
    
  }
}