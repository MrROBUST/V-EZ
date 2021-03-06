#######################################################################################################################
#
#  Copyright (c) 2017-2018 Advanced Micro Devices, Inc. All Rights Reserved.
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
# #######################################################################################################################

if(WIN32)
    set(PLATFORM_LIB win64) 
    file(COPY ${VEZ_ROOT_DIR}/Libs/Assimp/bin/win64/assimp-vc140-mt.dll DESTINATION "${VEZ_OUTPUT_DIRECTORY}")
elseif(APPLE)
    set(PLATFORM_LIB osx64)
elseif(UNIX)
    set(PLATFORM_LIB linux64)
endif(WIN32)

include_directories(
    ${VEZ_ROOT_DIR}/Source
    ${VEZ_ROOT_DIR}/Libs/Assimp/include
    ${VEZ_ROOT_DIR}/Libs/glfw/include
    ${VEZ_ROOT_DIR}/Libs/glm/include    
    ${VEZ_ROOT_DIR}/Libs/stb/include
)

link_directories(
    ${VEZ_ROOT_DIR}/Libs/Assimp/lib/${PLATFORM_LIB}
    ${VEZ_ROOT_DIR}/Libs/glfw/lib/${PLATFORM_LIB}    
)

add_subdirectory(MipmapGeneration)
add_subdirectory(MultiWindow)
add_subdirectory(OcclusionCulling)
add_subdirectory(PipelineReflection)
add_subdirectory(ShadowMapping)
add_subdirectory(SimpleCompute)
add_subdirectory(SimpleQuad)
add_subdirectory(SoftwareRasterization)
add_subdirectory(Subpasses)
add_subdirectory(VulkanMemory)