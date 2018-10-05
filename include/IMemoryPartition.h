/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
#ifndef IMEMORY_PARTITION_H
#define IMEMORY_PARTITION_H

#include <stdio.h>

class IMemoryPartition
{
public:
	virtual ~IMemoryPartition() {}

	virtual void*		allocate(size_t size)=0;
	virtual void		deallocate(void *)=0;
};

void *operator new (size_t size, IMemoryPartition *partition) throw();
void operator delete (void *p, IMemoryPartition *partition);

template<class T> T* create(IMemoryPartition *partition);
template<class T> void destroy(T* p, IMemoryPartition *partition);

#endif //IMEMORY_PARTITION_H
