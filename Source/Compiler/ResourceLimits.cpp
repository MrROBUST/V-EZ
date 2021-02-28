//
// Copyright (C) 2016 Google, Inc.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
//    Neither the name of Google Inc. nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cctype>

#include "ResourceLimits.h"

namespace glslang {


const TBuiltInResource DefaultTBuiltInResource = []() -> TBuiltInResource
{
    TBuiltInResource resource;
    resource.maxLights = 32;
    resource.maxClipPlanes = 6;
    resource.maxTextureUnits = 32;
    resource.maxTextureCoords = 32;
    resource.maxVertexAttribs = 64;
    resource.maxVertexUniformComponents = 4096;
    resource.maxVaryingFloats = 64;
    resource.maxVertexTextureImageUnits = 32;
    resource.maxCombinedTextureImageUnits = 80;
    resource.maxTextureImageUnits = 32;
    resource.maxFragmentUniformComponents = 4096;
    resource.maxDrawBuffers = 32;
    resource.maxVertexUniformVectors = 128;
    resource.maxVaryingVectors = 8;
    resource.maxFragmentUniformVectors = 16;
    resource.maxVertexOutputVectors = 16;
    resource.maxFragmentInputVectors = 15;
    resource.minProgramTexelOffset = -8;
    resource.maxProgramTexelOffset = 7;
    resource.maxClipDistances = 8;
    resource.maxComputeWorkGroupCountX = 65535;
    resource.maxComputeWorkGroupCountY = 65535;
    resource.maxComputeWorkGroupCountZ = 65535;
    resource.maxComputeWorkGroupSizeX = 1024;
    resource.maxComputeWorkGroupSizeY = 1024;
    resource.maxComputeWorkGroupSizeZ = 64;
    resource.maxComputeUniformComponents = 1024;
    resource.maxComputeTextureImageUnits = 16;
    resource.maxComputeImageUniforms = 8;
    resource.maxComputeAtomicCounters = 8;
    resource.maxComputeAtomicCounterBuffers = 1;
    resource.maxVaryingComponents = 60;
    resource.maxVertexOutputComponents = 64;
    resource.maxGeometryInputComponents = 64;
    resource.maxGeometryOutputComponents = 128;
    resource.maxFragmentInputComponents = 128;
    resource.maxImageUnits = 8;
    resource.maxCombinedImageUnitsAndFragmentOutputs = 8;
    resource.maxCombinedShaderOutputResources = 8;
    resource.maxImageSamples = 0;
    resource.maxVertexImageUniforms = 0;
    resource.maxTessControlImageUniforms = 0;
    resource.maxTessEvaluationImageUniforms = 0;
    resource.maxGeometryImageUniforms = 0;
    resource.maxFragmentImageUniforms = 8;
    resource.maxCombinedImageUniforms = 8;
    resource.maxGeometryTextureImageUnits = 16;
    resource.maxGeometryOutputVertices = 256;
    resource.maxGeometryTotalOutputComponents = 1024;
    resource.maxGeometryUniformComponents = 1024;
    resource.maxGeometryVaryingComponents = 64;
    resource.maxTessControlInputComponents = 128;
    resource.maxTessControlOutputComponents = 128;
    resource.maxTessControlTextureImageUnits = 16;
    resource.maxTessControlUniformComponents = 1024;
    resource.maxTessControlTotalOutputComponents = 4096;
    resource.maxTessEvaluationInputComponents = 128;
    resource.maxTessEvaluationOutputComponents = 128;
    resource.maxTessEvaluationTextureImageUnits = 16;
    resource.maxTessEvaluationUniformComponents = 1024;
    resource.maxTessPatchComponents = 120;
    resource.maxPatchVertices = 32;
    resource.maxTessGenLevel = 64;
    resource.maxViewports = 16;
    resource.maxVertexAtomicCounters = 0;
    resource.maxTessControlAtomicCounters = 0;
    resource.maxTessEvaluationAtomicCounters = 0;
    resource.maxGeometryAtomicCounters = 0;
    resource.maxFragmentAtomicCounters = 8;
    resource.maxCombinedAtomicCounters = 8;
    resource.maxAtomicCounterBindings = 1;
    resource.maxVertexAtomicCounterBuffers = 0;
    resource.maxTessControlAtomicCounterBuffers = 0;
    resource.maxTessEvaluationAtomicCounterBuffers = 0;
    resource.maxGeometryAtomicCounterBuffers = 0;
    resource.maxFragmentAtomicCounterBuffers = 1;
    resource.maxCombinedAtomicCounterBuffers = 1;
    resource.maxAtomicCounterBufferSize = 16384;
    resource.maxTransformFeedbackBuffers = 4;
    resource.maxTransformFeedbackInterleavedComponents = 64;
    resource.maxCullDistances = 8;
    resource.maxCombinedClipAndCullDistances = 8;
    resource.maxSamples = 4;
    resource.limits.nonInductiveForLoops = 1;
    resource.limits.whileLoops = 1;
    resource.limits.doWhileLoops = 1;
    resource.limits.generalUniformIndexing = 1;
    resource.limits.generalAttributeMatrixVectorIndexing = 1;
    resource.limits.generalVaryingIndexing = 1;
    resource.limits.generalSamplerIndexing = 1;
    resource.limits.generalVariableIndexing = 1;
    resource.limits.generalConstantMatrixVectorIndexing = 1;
    return resource;
}();

std::string GetDefaultTBuiltInResourceString()
{
    std::ostringstream ostream;

    ostream << "MaxLights "                                 << DefaultTBuiltInResource.maxLights << "\n"
            << "MaxClipPlanes "                             << DefaultTBuiltInResource.maxClipPlanes << "\n"
            << "MaxTextureUnits "                           << DefaultTBuiltInResource.maxTextureUnits << "\n"
            << "MaxTextureCoords "                          << DefaultTBuiltInResource.maxTextureCoords << "\n"
            << "MaxVertexAttribs "                          << DefaultTBuiltInResource.maxVertexAttribs << "\n"
            << "MaxVertexUniformComponents "                << DefaultTBuiltInResource.maxVertexUniformComponents << "\n"
            << "MaxVaryingFloats "                          << DefaultTBuiltInResource.maxVaryingFloats << "\n"
            << "MaxVertexTextureImageUnits "                << DefaultTBuiltInResource.maxVertexTextureImageUnits << "\n"
            << "MaxCombinedTextureImageUnits "              << DefaultTBuiltInResource.maxCombinedTextureImageUnits << "\n"
            << "MaxTextureImageUnits "                      << DefaultTBuiltInResource.maxTextureImageUnits << "\n"
            << "MaxFragmentUniformComponents "              << DefaultTBuiltInResource.maxFragmentUniformComponents << "\n"
            << "MaxDrawBuffers "                            << DefaultTBuiltInResource.maxDrawBuffers << "\n"
            << "MaxVertexUniformVectors "                   << DefaultTBuiltInResource.maxVertexUniformVectors << "\n"
            << "MaxVaryingVectors "                         << DefaultTBuiltInResource.maxVaryingVectors << "\n"
            << "MaxFragmentUniformVectors "                 << DefaultTBuiltInResource.maxFragmentUniformVectors << "\n"
            << "MaxVertexOutputVectors "                    << DefaultTBuiltInResource.maxVertexOutputVectors << "\n"
            << "MaxFragmentInputVectors "                   << DefaultTBuiltInResource.maxFragmentInputVectors << "\n"
            << "MinProgramTexelOffset "                     << DefaultTBuiltInResource.minProgramTexelOffset << "\n"
            << "MaxProgramTexelOffset "                     << DefaultTBuiltInResource.maxProgramTexelOffset << "\n"
            << "MaxClipDistances "                          << DefaultTBuiltInResource.maxClipDistances << "\n"
            << "MaxComputeWorkGroupCountX "                 << DefaultTBuiltInResource.maxComputeWorkGroupCountX << "\n"
            << "MaxComputeWorkGroupCountY "                 << DefaultTBuiltInResource.maxComputeWorkGroupCountY << "\n"
            << "MaxComputeWorkGroupCountZ "                 << DefaultTBuiltInResource.maxComputeWorkGroupCountZ << "\n"
            << "MaxComputeWorkGroupSizeX "                  << DefaultTBuiltInResource.maxComputeWorkGroupSizeX << "\n"
            << "MaxComputeWorkGroupSizeY "                  << DefaultTBuiltInResource.maxComputeWorkGroupSizeY << "\n"
            << "MaxComputeWorkGroupSizeZ "                  << DefaultTBuiltInResource.maxComputeWorkGroupSizeZ << "\n"
            << "MaxComputeUniformComponents "               << DefaultTBuiltInResource.maxComputeUniformComponents << "\n"
            << "MaxComputeTextureImageUnits "               << DefaultTBuiltInResource.maxComputeTextureImageUnits << "\n"
            << "MaxComputeImageUniforms "                   << DefaultTBuiltInResource.maxComputeImageUniforms << "\n"
            << "MaxComputeAtomicCounters "                  << DefaultTBuiltInResource.maxComputeAtomicCounters << "\n"
            << "MaxComputeAtomicCounterBuffers "            << DefaultTBuiltInResource.maxComputeAtomicCounterBuffers << "\n"
            << "MaxVaryingComponents "                      << DefaultTBuiltInResource.maxVaryingComponents << "\n"
            << "MaxVertexOutputComponents "                 << DefaultTBuiltInResource.maxVertexOutputComponents << "\n"
            << "MaxGeometryInputComponents "                << DefaultTBuiltInResource.maxGeometryInputComponents << "\n"
            << "MaxGeometryOutputComponents "               << DefaultTBuiltInResource.maxGeometryOutputComponents << "\n"
            << "MaxFragmentInputComponents "                << DefaultTBuiltInResource.maxFragmentInputComponents << "\n"
            << "MaxImageUnits "                             << DefaultTBuiltInResource.maxImageUnits << "\n"
            << "MaxCombinedImageUnitsAndFragmentOutputs "   << DefaultTBuiltInResource.maxCombinedImageUnitsAndFragmentOutputs << "\n"
            << "MaxCombinedShaderOutputResources "          << DefaultTBuiltInResource.maxCombinedShaderOutputResources << "\n"
            << "MaxImageSamples "                           << DefaultTBuiltInResource.maxImageSamples << "\n"
            << "MaxVertexImageUniforms "                    << DefaultTBuiltInResource.maxVertexImageUniforms << "\n"
            << "MaxTessControlImageUniforms "               << DefaultTBuiltInResource.maxTessControlImageUniforms << "\n"
            << "MaxTessEvaluationImageUniforms "            << DefaultTBuiltInResource.maxTessEvaluationImageUniforms << "\n"
            << "MaxGeometryImageUniforms "                  << DefaultTBuiltInResource.maxGeometryImageUniforms << "\n"
            << "MaxFragmentImageUniforms "                  << DefaultTBuiltInResource.maxFragmentImageUniforms << "\n"
            << "MaxCombinedImageUniforms "                  << DefaultTBuiltInResource.maxCombinedImageUniforms << "\n"
            << "MaxGeometryTextureImageUnits "              << DefaultTBuiltInResource.maxGeometryTextureImageUnits << "\n"
            << "MaxGeometryOutputVertices "                 << DefaultTBuiltInResource.maxGeometryOutputVertices << "\n"
            << "MaxGeometryTotalOutputComponents "          << DefaultTBuiltInResource.maxGeometryTotalOutputComponents << "\n"
            << "MaxGeometryUniformComponents "              << DefaultTBuiltInResource.maxGeometryUniformComponents << "\n"
            << "MaxGeometryVaryingComponents "              << DefaultTBuiltInResource.maxGeometryVaryingComponents << "\n"
            << "MaxTessControlInputComponents "             << DefaultTBuiltInResource.maxTessControlInputComponents << "\n"
            << "MaxTessControlOutputComponents "            << DefaultTBuiltInResource.maxTessControlOutputComponents << "\n"
            << "MaxTessControlTextureImageUnits "           << DefaultTBuiltInResource.maxTessControlTextureImageUnits << "\n"
            << "MaxTessControlUniformComponents "           << DefaultTBuiltInResource.maxTessControlUniformComponents << "\n"
            << "MaxTessControlTotalOutputComponents "       << DefaultTBuiltInResource.maxTessControlTotalOutputComponents << "\n"
            << "MaxTessEvaluationInputComponents "          << DefaultTBuiltInResource.maxTessEvaluationInputComponents << "\n"
            << "MaxTessEvaluationOutputComponents "         << DefaultTBuiltInResource.maxTessEvaluationOutputComponents << "\n"
            << "MaxTessEvaluationTextureImageUnits "        << DefaultTBuiltInResource.maxTessEvaluationTextureImageUnits << "\n"
            << "MaxTessEvaluationUniformComponents "        << DefaultTBuiltInResource.maxTessEvaluationUniformComponents << "\n"
            << "MaxTessPatchComponents "                    << DefaultTBuiltInResource.maxTessPatchComponents << "\n"
            << "MaxPatchVertices "                          << DefaultTBuiltInResource.maxPatchVertices << "\n"
            << "MaxTessGenLevel "                           << DefaultTBuiltInResource.maxTessGenLevel << "\n"
            << "MaxViewports "                              << DefaultTBuiltInResource.maxViewports << "\n"
            << "MaxVertexAtomicCounters "                   << DefaultTBuiltInResource.maxVertexAtomicCounters << "\n"
            << "MaxTessControlAtomicCounters "              << DefaultTBuiltInResource.maxTessControlAtomicCounters << "\n"
            << "MaxTessEvaluationAtomicCounters "           << DefaultTBuiltInResource.maxTessEvaluationAtomicCounters << "\n"
            << "MaxGeometryAtomicCounters "                 << DefaultTBuiltInResource.maxGeometryAtomicCounters << "\n"
            << "MaxFragmentAtomicCounters "                 << DefaultTBuiltInResource.maxFragmentAtomicCounters << "\n"
            << "MaxCombinedAtomicCounters "                 << DefaultTBuiltInResource.maxCombinedAtomicCounters << "\n"
            << "MaxAtomicCounterBindings "                  << DefaultTBuiltInResource.maxAtomicCounterBindings << "\n"
            << "MaxVertexAtomicCounterBuffers "             << DefaultTBuiltInResource.maxVertexAtomicCounterBuffers << "\n"
            << "MaxTessControlAtomicCounterBuffers "        << DefaultTBuiltInResource.maxTessControlAtomicCounterBuffers << "\n"
            << "MaxTessEvaluationAtomicCounterBuffers "     << DefaultTBuiltInResource.maxTessEvaluationAtomicCounterBuffers << "\n"
            << "MaxGeometryAtomicCounterBuffers "           << DefaultTBuiltInResource.maxGeometryAtomicCounterBuffers << "\n"
            << "MaxFragmentAtomicCounterBuffers "           << DefaultTBuiltInResource.maxFragmentAtomicCounterBuffers << "\n"
            << "MaxCombinedAtomicCounterBuffers "           << DefaultTBuiltInResource.maxCombinedAtomicCounterBuffers << "\n"
            << "MaxAtomicCounterBufferSize "                << DefaultTBuiltInResource.maxAtomicCounterBufferSize << "\n"
            << "MaxTransformFeedbackBuffers "               << DefaultTBuiltInResource.maxTransformFeedbackBuffers << "\n"
            << "MaxTransformFeedbackInterleavedComponents " << DefaultTBuiltInResource.maxTransformFeedbackInterleavedComponents << "\n"
            << "MaxCullDistances "                          << DefaultTBuiltInResource.maxCullDistances << "\n"
            << "MaxCombinedClipAndCullDistances "           << DefaultTBuiltInResource.maxCombinedClipAndCullDistances << "\n"
            << "MaxSamples "                                << DefaultTBuiltInResource.maxSamples << "\n"

            << "nonInductiveForLoops "                      << DefaultTBuiltInResource.limits.nonInductiveForLoops << "\n"
            << "whileLoops "                                << DefaultTBuiltInResource.limits.whileLoops << "\n"
            << "doWhileLoops "                              << DefaultTBuiltInResource.limits.doWhileLoops << "\n"
            << "generalUniformIndexing "                    << DefaultTBuiltInResource.limits.generalUniformIndexing << "\n"
            << "generalAttributeMatrixVectorIndexing "      << DefaultTBuiltInResource.limits.generalAttributeMatrixVectorIndexing << "\n"
            << "generalVaryingIndexing "                    << DefaultTBuiltInResource.limits.generalVaryingIndexing << "\n"
            << "generalSamplerIndexing "                    << DefaultTBuiltInResource.limits.generalSamplerIndexing << "\n"
            << "generalVariableIndexing "                   << DefaultTBuiltInResource.limits.generalVariableIndexing << "\n"
            << "generalConstantMatrixVectorIndexing "       << DefaultTBuiltInResource.limits.generalConstantMatrixVectorIndexing << "\n"
      ;

    return ostream.str();
}

void DecodeResourceLimits(TBuiltInResource* resources, char* config)
{
    static const char* delims = " \t\n\r";

    size_t pos     = 0;
    std::string configStr(config);

    while ((pos = configStr.find_first_not_of(delims, pos)) != std::string::npos) {
        const size_t token_s = pos;
        const size_t token_e = configStr.find_first_of(delims, token_s);
        const size_t value_s = configStr.find_first_not_of(delims, token_e);
        const size_t value_e = configStr.find_first_of(delims, value_s);
        pos = value_e;

        // Faster to use compare(), but prefering readability.
        const std::string tokenStr = configStr.substr(token_s, token_e-token_s);
        const std::string valueStr = configStr.substr(value_s, value_e-value_s);

        if (value_s == std::string::npos || ! (valueStr[0] == '-' || isdigit(valueStr[0]))) {
            printf("Error: '%s' bad .conf file.  Each name must be followed by one number.\n",
                   valueStr.c_str());
            return;
        }

        const int value = std::atoi(valueStr.c_str());

        if (tokenStr == "MaxLights")
            resources->maxLights = value;
        else if (tokenStr == "MaxClipPlanes")
            resources->maxClipPlanes = value;
        else if (tokenStr == "MaxTextureUnits")
            resources->maxTextureUnits = value;
        else if (tokenStr == "MaxTextureCoords")
            resources->maxTextureCoords = value;
        else if (tokenStr == "MaxVertexAttribs")
            resources->maxVertexAttribs = value;
        else if (tokenStr == "MaxVertexUniformComponents")
            resources->maxVertexUniformComponents = value;
        else if (tokenStr == "MaxVaryingFloats")
            resources->maxVaryingFloats = value;
        else if (tokenStr == "MaxVertexTextureImageUnits")
            resources->maxVertexTextureImageUnits = value;
        else if (tokenStr == "MaxCombinedTextureImageUnits")
            resources->maxCombinedTextureImageUnits = value;
        else if (tokenStr == "MaxTextureImageUnits")
            resources->maxTextureImageUnits = value;
        else if (tokenStr == "MaxFragmentUniformComponents")
            resources->maxFragmentUniformComponents = value;
        else if (tokenStr == "MaxDrawBuffers")
            resources->maxDrawBuffers = value;
        else if (tokenStr == "MaxVertexUniformVectors")
            resources->maxVertexUniformVectors = value;
        else if (tokenStr == "MaxVaryingVectors")
            resources->maxVaryingVectors = value;
        else if (tokenStr == "MaxFragmentUniformVectors")
            resources->maxFragmentUniformVectors = value;
        else if (tokenStr == "MaxVertexOutputVectors")
            resources->maxVertexOutputVectors = value;
        else if (tokenStr == "MaxFragmentInputVectors")
            resources->maxFragmentInputVectors = value;
        else if (tokenStr == "MinProgramTexelOffset")
            resources->minProgramTexelOffset = value;
        else if (tokenStr == "MaxProgramTexelOffset")
            resources->maxProgramTexelOffset = value;
        else if (tokenStr == "MaxClipDistances")
            resources->maxClipDistances = value;
        else if (tokenStr == "MaxComputeWorkGroupCountX")
            resources->maxComputeWorkGroupCountX = value;
        else if (tokenStr == "MaxComputeWorkGroupCountY")
            resources->maxComputeWorkGroupCountY = value;
        else if (tokenStr == "MaxComputeWorkGroupCountZ")
            resources->maxComputeWorkGroupCountZ = value;
        else if (tokenStr == "MaxComputeWorkGroupSizeX")
            resources->maxComputeWorkGroupSizeX = value;
        else if (tokenStr == "MaxComputeWorkGroupSizeY")
            resources->maxComputeWorkGroupSizeY = value;
        else if (tokenStr == "MaxComputeWorkGroupSizeZ")
            resources->maxComputeWorkGroupSizeZ = value;
        else if (tokenStr == "MaxComputeUniformComponents")
            resources->maxComputeUniformComponents = value;
        else if (tokenStr == "MaxComputeTextureImageUnits")
            resources->maxComputeTextureImageUnits = value;
        else if (tokenStr == "MaxComputeImageUniforms")
            resources->maxComputeImageUniforms = value;
        else if (tokenStr == "MaxComputeAtomicCounters")
            resources->maxComputeAtomicCounters = value;
        else if (tokenStr == "MaxComputeAtomicCounterBuffers")
            resources->maxComputeAtomicCounterBuffers = value;
        else if (tokenStr == "MaxVaryingComponents")
            resources->maxVaryingComponents = value;
        else if (tokenStr == "MaxVertexOutputComponents")
            resources->maxVertexOutputComponents = value;
        else if (tokenStr == "MaxGeometryInputComponents")
            resources->maxGeometryInputComponents = value;
        else if (tokenStr == "MaxGeometryOutputComponents")
            resources->maxGeometryOutputComponents = value;
        else if (tokenStr == "MaxFragmentInputComponents")
            resources->maxFragmentInputComponents = value;
        else if (tokenStr == "MaxImageUnits")
            resources->maxImageUnits = value;
        else if (tokenStr == "MaxCombinedImageUnitsAndFragmentOutputs")
            resources->maxCombinedImageUnitsAndFragmentOutputs = value;
        else if (tokenStr == "MaxCombinedShaderOutputResources")
            resources->maxCombinedShaderOutputResources = value;
        else if (tokenStr == "MaxImageSamples")
            resources->maxImageSamples = value;
        else if (tokenStr == "MaxVertexImageUniforms")
            resources->maxVertexImageUniforms = value;
        else if (tokenStr == "MaxTessControlImageUniforms")
            resources->maxTessControlImageUniforms = value;
        else if (tokenStr == "MaxTessEvaluationImageUniforms")
            resources->maxTessEvaluationImageUniforms = value;
        else if (tokenStr == "MaxGeometryImageUniforms")
            resources->maxGeometryImageUniforms = value;
        else if (tokenStr == "MaxFragmentImageUniforms")
            resources->maxFragmentImageUniforms = value;
        else if (tokenStr == "MaxCombinedImageUniforms")
            resources->maxCombinedImageUniforms = value;
        else if (tokenStr == "MaxGeometryTextureImageUnits")
            resources->maxGeometryTextureImageUnits = value;
        else if (tokenStr == "MaxGeometryOutputVertices")
            resources->maxGeometryOutputVertices = value;
        else if (tokenStr == "MaxGeometryTotalOutputComponents")
            resources->maxGeometryTotalOutputComponents = value;
        else if (tokenStr == "MaxGeometryUniformComponents")
            resources->maxGeometryUniformComponents = value;
        else if (tokenStr == "MaxGeometryVaryingComponents")
            resources->maxGeometryVaryingComponents = value;
        else if (tokenStr == "MaxTessControlInputComponents")
            resources->maxTessControlInputComponents = value;
        else if (tokenStr == "MaxTessControlOutputComponents")
            resources->maxTessControlOutputComponents = value;
        else if (tokenStr == "MaxTessControlTextureImageUnits")
            resources->maxTessControlTextureImageUnits = value;
        else if (tokenStr == "MaxTessControlUniformComponents")
            resources->maxTessControlUniformComponents = value;
        else if (tokenStr == "MaxTessControlTotalOutputComponents")
            resources->maxTessControlTotalOutputComponents = value;
        else if (tokenStr == "MaxTessEvaluationInputComponents")
            resources->maxTessEvaluationInputComponents = value;
        else if (tokenStr == "MaxTessEvaluationOutputComponents")
            resources->maxTessEvaluationOutputComponents = value;
        else if (tokenStr == "MaxTessEvaluationTextureImageUnits")
            resources->maxTessEvaluationTextureImageUnits = value;
        else if (tokenStr == "MaxTessEvaluationUniformComponents")
            resources->maxTessEvaluationUniformComponents = value;
        else if (tokenStr == "MaxTessPatchComponents")
            resources->maxTessPatchComponents = value;
        else if (tokenStr == "MaxPatchVertices")
            resources->maxPatchVertices = value;
        else if (tokenStr == "MaxTessGenLevel")
            resources->maxTessGenLevel = value;
        else if (tokenStr == "MaxViewports")
            resources->maxViewports = value;
        else if (tokenStr == "MaxVertexAtomicCounters")
            resources->maxVertexAtomicCounters = value;
        else if (tokenStr == "MaxTessControlAtomicCounters")
            resources->maxTessControlAtomicCounters = value;
        else if (tokenStr == "MaxTessEvaluationAtomicCounters")
            resources->maxTessEvaluationAtomicCounters = value;
        else if (tokenStr == "MaxGeometryAtomicCounters")
            resources->maxGeometryAtomicCounters = value;
        else if (tokenStr == "MaxFragmentAtomicCounters")
            resources->maxFragmentAtomicCounters = value;
        else if (tokenStr == "MaxCombinedAtomicCounters")
            resources->maxCombinedAtomicCounters = value;
        else if (tokenStr == "MaxAtomicCounterBindings")
            resources->maxAtomicCounterBindings = value;
        else if (tokenStr == "MaxVertexAtomicCounterBuffers")
            resources->maxVertexAtomicCounterBuffers = value;
        else if (tokenStr == "MaxTessControlAtomicCounterBuffers")
            resources->maxTessControlAtomicCounterBuffers = value;
        else if (tokenStr == "MaxTessEvaluationAtomicCounterBuffers")
            resources->maxTessEvaluationAtomicCounterBuffers = value;
        else if (tokenStr == "MaxGeometryAtomicCounterBuffers")
            resources->maxGeometryAtomicCounterBuffers = value;
        else if (tokenStr == "MaxFragmentAtomicCounterBuffers")
            resources->maxFragmentAtomicCounterBuffers = value;
        else if (tokenStr == "MaxCombinedAtomicCounterBuffers")
            resources->maxCombinedAtomicCounterBuffers = value;
        else if (tokenStr == "MaxAtomicCounterBufferSize")
            resources->maxAtomicCounterBufferSize = value;
        else if (tokenStr == "MaxTransformFeedbackBuffers")
            resources->maxTransformFeedbackBuffers = value;
        else if (tokenStr == "MaxTransformFeedbackInterleavedComponents")
            resources->maxTransformFeedbackInterleavedComponents = value;
        else if (tokenStr == "MaxCullDistances")
            resources->maxCullDistances = value;
        else if (tokenStr == "MaxCombinedClipAndCullDistances")
            resources->maxCombinedClipAndCullDistances = value;
        else if (tokenStr == "MaxSamples")
            resources->maxSamples = value;
        else if (tokenStr == "nonInductiveForLoops")
            resources->limits.nonInductiveForLoops = (value != 0);
        else if (tokenStr == "whileLoops")
            resources->limits.whileLoops = (value != 0);
        else if (tokenStr == "doWhileLoops")
            resources->limits.doWhileLoops = (value != 0);
        else if (tokenStr == "generalUniformIndexing")
            resources->limits.generalUniformIndexing = (value != 0);
        else if (tokenStr == "generalAttributeMatrixVectorIndexing")
            resources->limits.generalAttributeMatrixVectorIndexing = (value != 0);
        else if (tokenStr == "generalVaryingIndexing")
            resources->limits.generalVaryingIndexing = (value != 0);
        else if (tokenStr == "generalSamplerIndexing")
            resources->limits.generalSamplerIndexing = (value != 0);
        else if (tokenStr == "generalVariableIndexing")
            resources->limits.generalVariableIndexing = (value != 0);
        else if (tokenStr == "generalConstantMatrixVectorIndexing")
            resources->limits.generalConstantMatrixVectorIndexing = (value != 0);
        else
            printf("Warning: unrecognized limit (%s) in configuration file.\n", tokenStr.c_str());

    }
}

}  // end namespace glslang
