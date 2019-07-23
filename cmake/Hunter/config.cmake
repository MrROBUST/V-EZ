# Copyright (c) 2019 Mathieu-André Chiasson
# All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

hunter_config(SPIRV-Headers
    VERSION v1.4.1-p2
    URL https://github.com/mchiasson/SPIRV-Headers/archive/v1.4.1-p2.tar.gz
    SHA1 efc784e17102b75e3980e91dd5e090b959461ff0
    CMAKE_ARGS SPIRV_HEADERS_ENABLE_EXAMPLES=OFF
)

hunter_config(SPIRV-Tools
    VERSION v2019.2-p4
    URL https://github.com/mchiasson/SPIRV-Tools/archive/v2019.2-p4.tar.gz
    SHA1 959b2629ad7e2041c3086ccbed6d39d0bc77c5f7
    CMAKE_ARGS SPIRV_SKIP_TESTS=ON SPIRV_WERROR=OFF
)

hunter_config(glslang
    VERSION v7.11.3214-p0
    URL https://github.com/mchiasson/glslang/archive/v7.11.3214-p0.tar.gz
    SHA1 9e73d0a84eb34a903f729ce4e28e2d1a8b60aa6a
    CMAKE_ARGS ENABLE_HLSL=ON BUILD_TESTING=OFF
)

hunter_config(shaderc
    VERSION v2009.0-p0
    URL https://github.com/mchiasson/shaderc/archive/v2009.0-p0.tar.gz
    SHA1 127b55aec421c43416998dbbd2c9eca482e7a92d
    CMAKE_ARGS SHADERC_SKIP_TESTS=ON
)
