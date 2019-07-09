// Approximation of Pi using a simple, and not optimized, CUDA program
// Copyleft Alessandro Re

#include <stdio.h>
#include <cuda.h>
#include <curand_kernel.h>

typedef unsigned long long Count;

const Count WARP_SIZE = 32; // Warp size
const Count NBLOCKS = 64; // Number of total cuda cores on my GPU

__global__ void picount(Count *totals, Count iterPerThread) {
	__shared__ Count counter[WARP_SIZE];

	int tid = threadIdx.x + blockIdx.x * blockDim.x;

	curandState_t rng;
	curand_init(clock64(), tid, 0, &rng);

  Count cnt = 0;
	// Computation loop
	for (int i = 0; i < iterPerThread; i++) {
		float x = curand_uniform(&rng); 
    float y = curand_uniform(&rng);
    if(x*x + y*y <= 1.0) cnt++;
  }
  
  counter[threadIdx.x] = cnt;

	if (threadIdx.x == 0) {
		totals[blockIdx.x] = 0;
		for (int i = 0; i < WARP_SIZE; i++) {
			totals[blockIdx.x] += counter[i];
		}
	}
}

int main(int argc, char **argv) {
	int nDevices;

	cudaGetDeviceCount(&nDevices);
	if (nDevices < 1) {
		printf("CUDA device missing! Do you need to use optirun?\n");
		return 1;
	}

	printf("------CUDA Devices------\n");
  for (int i = 0; i < nDevices; i++) {
    cudaDeviceProp prop;
    cudaGetDeviceProperties(&prop, i);
    printf("Device Number: %d\n", i);
    printf("  Device name: %s\n", prop.name);
    printf("  Memory Clock Rate (KHz): %d\n",
           prop.memoryClockRate);
  }
	
	
  Count totalIterations;
  scanf("%lld", &totalIterations);

  Count totalThreads = (WARP_SIZE * NBLOCKS);
  Count iterPerThread = (totalIterations + totalThreads - 1LL)/(totalThreads);
  totalIterations = iterPerThread * totalThreads;
  printf("\nStarting simulation with %lld blocks, %lld threads per block (warps), and a total of %lld iterations\n", NBLOCKS, WARP_SIZE, totalIterations);

  Count *hOut, *dOut;
	hOut = new Count[NBLOCKS]; 
  cudaMalloc(&dOut, sizeof(Count) * NBLOCKS);

	picount<<<NBLOCKS, WARP_SIZE>>>(dOut, iterPerThread);

	cudaMemcpy(hOut, dOut, sizeof(Count) * NBLOCKS, cudaMemcpyDeviceToHost);
	cudaFree(dOut);

	Count total = 0;
	for (int i = 0; i < NBLOCKS; i++) {
		total += hOut[i];
	}
	printf("Approximated PI using %lld random tests\n", totalIterations);

	double pi = 4.0 * (double)total/(double)totalIterations;
	printf("PI ~= %.9lf\n", pi);

	return 0;
}