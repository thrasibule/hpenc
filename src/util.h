/*
 * Copyright (c) 2014, Vsevolod Stakhov
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *	 * Redistributions of source code must retain the above copyright
 *	   notice, this list of conditions and the following disclaimer.
 *	 * Redistributions in binary form must reproduce the above copyright
 *	   notice, this list of conditions and the following disclaimer in the
 *	   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef UTIL_H_
#define UTIL_H_

#include <memory>
#include <string>
#include "common.h"

namespace hpenc {

namespace util {

std::string base32EncodeKey(const SessionKey *in);
std::unique_ptr<SessionKey> base32DecodeKey(const std::string &in);

std::vector<byte> base64Decode(const std::string& input);
std::string base64Encode(const byte *input, size_t len);

template<typename T, typename ...Args>
::std::unique_ptr<T> make_unique(Args&& ...args)
{
    return ::std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

std::unique_ptr<SessionKey> genPSK(AeadAlgorithm alg);

size_t atomicRead(int fd, byte *buf, size_t n);
size_t atomicWrite(int fd, const byte *buf, size_t n);

std::unique_ptr<std::vector<byte> > readPassphrase();

} // util namespace

} // hpenc namespace

#endif /* UTIL_H_ */
