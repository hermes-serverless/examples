## Sum reduce

This simple function accepts a integer `n` followed by `n` integers. The output will be one integer representing the sum of the `n` numbers given. Example:


```
input: 5 1 2 3 4 5
output: 15
```
Deploy with the Hermes CLI using:

```bash
$ cd pathToReduceSumFolder
$ hermes function:deploy
```

Start a sync run using:

```bash
hermes function:run <yourUsername>/reduce-sum:1.0.0
```
Or a async run:
```bash
hermes function:run <yourUsername>/reduce-sum:1.0.0 --async
```