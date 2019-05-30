#include <hip/hip_runtime.h>
/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <cstdio>
#include <thrust/detail/config.h>
#include <thrust/system/cuda/detail/bulk.h>

namespace thrust
{
    namespace system
    {
        namespace cuda
        {
            namespace detail
            {

                inline __host__ __device__ void throw_on_error(hipError_t  error,
                                                               const char* message)
                {
                    thrust::system::cuda::detail::bulk_::detail::throw_on_error(error, message);
                }

#ifdef __HIP_PLATFORM_NVCC__
                inline __host__ __device__ void throw_on_error(cudaError_t error,
                                                               const char* message)
                {
                    thrust::system::cuda::detail::bulk_::detail::throw_on_error(error, message);
                }
#endif

            } // end detail
        } // end cuda
    } // end system
} // end thrust
