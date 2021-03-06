/*  This file is part of the Vc library. {{{
Copyright © 2010-2015 Matthias Kretz <kretz@kde.org>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the names of contributing organizations nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

}}}*/

#ifndef VC_VERSION_H_
#define VC_VERSION_H_

#define Vc_VERSION_STRING "1.0.79-dev"
#define Vc_VERSION_NUMBER 0x01009f
#define Vc_VERSION_CHECK(major, minor, patch) ((major << 16) | (minor << 8) | (patch << 1))
#define Vc_LIBRARY_ABI_VERSION 5

namespace Vc_VERSIONED_NAMESPACE
{
    static inline const char *versionString() {
        return Vc_VERSION_STRING;
    }

    static inline unsigned int versionNumber() {
        return Vc_VERSION_NUMBER;
    }
}

#if !defined(Vc_NO_VERSION_CHECK) && !defined(Vc_COMPILE_LIB)
namespace Vc_VERSIONED_NAMESPACE
{
namespace Common
{
    void checkLibraryAbi(unsigned int compileTimeAbi, unsigned int versionNumber, const char *versionString);
    namespace {
        static struct runLibraryAbiCheck
        {
            runLibraryAbiCheck() {
                checkLibraryAbi(Vc_LIBRARY_ABI_VERSION, Vc_VERSION_NUMBER, Vc_VERSION_STRING);
            }
        } _runLibraryAbiCheck;
    }
}
}
#endif

#endif // VC_VERSION_H_
