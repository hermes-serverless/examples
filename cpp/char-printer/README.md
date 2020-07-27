## Char printer

This simple function accepts a char followed by an integer `n`. The output will be the given char repeated `n` times. Example:


```
input: a 3
output: aaa
```

Deploy with the Hermes CLI using:

```bash
$ cd pathToCharPrinterFolder
$ hermes function deploy
```

Start a sync run using:

```bash
hermes function run run <yourUsername>/char-printer:1.0.0 --sync
```
Or a async run:
```bash
hermes function run run <yourUsername>/char-printer:1.0.0 --async
```
