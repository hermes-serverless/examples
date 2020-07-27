## GPU Pi Montecarlo

This function accepts a number for the number of iterations to run the Montercarlo's algorithm to approximate PI. 
The output will information on the host's GPU and the PI approximation. Example:


```
input: 1000000
output:
------CUDA Devices------
Device Number: 0
  Device name: GeForce MX150
  Memory Clock Rate (KHz): 3004000

Starting simulation with 64 blocks, 32 threads per block (warps), and a total of 1000001536 iterations
Approximated PI using 1000001536 random tests
PI ~= 3.141620254
```

Deploy with the Hermes CLI using:

```bash
$ cd pathToGPUPiMontecarlo
$ hermes function:deploy
```

Start a sync run using:

```bash
hermes function:run <yourUsername>/gpu-pi-montecarlo:1.0.0
```
Or a async run:
```bash
hermes function:run <yourUsername>/gpu-pi-montecarlo:1.0.0 --async
```
