CXX = clang++

CFLAGS = `pkg-config --libs --cflags opencv `

CXXFLAGS = $(CFLAGS)

calibration: calibration.cpp

test_akaze: test_akaze.cpp utils/utils.cpp
test_akaze_match: test_akaze_match.cpp utils/utils.cpp
test_kaze: test_kaze.cpp utils/utils.cpp
test_kaze_match: test_kaze_match.cpp utils/utils.cpp
