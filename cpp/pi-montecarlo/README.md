## PI - Montecarlo

This function uses multiple threads to estimate PI using the Montecarlo method. The input is two numbers `n`, `t`, representing, respectively, the total number of iterations to be done by the algorithm and the number of threads to be used. 

Deploy with the Hermes CLI using:

```bash
$ cd pi-montecarlo
$ hermes function:deploy
```

Start a sync run using:

```bash
hermes function:run <yourUsername>/pi-montecarlo:1.0.0
```
Or a async run:
```bash
hermes function:run <yourUsername>/pi-montecarlo:1.0.0 --async
```