/* vi:set ts=4 sw=4 expandtab:
 *
 * Copyright 2016, Chris Leishman (http://github.com/cleishm)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MEMSTREAM_H
#define MEMSTREAM_H

#ifdef WIN32

#include "..\..\Windows\Tests\fmem.h"

extern fmem fm;
extern FILE* open_memstream(char** mem, size_t* size);
#define fclose(f) fclose(memstream);memstream_buffer = NULL;
#define fflush(a) fflush(memstream);fmem_mem(&fm, &memstream_buffer, &memstream_size);

#else

#include <stdio.h>

#ifndef HAVE_OPEN_MEMSTREAM
FILE *open_memstream(char **ptr, size_t *sizeloc);
#endif

#endif//WIN32

#endif/*MEMSTREAM_H*/
