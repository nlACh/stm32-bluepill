## Data format:
Data transmission is fairly simple and unencrypted.

The format used is comma separated data, with identifiers for each block. Very similar to what [**James Bruton**](https://github.com/XRobots) over at [**XRobots**](www.xrobots.co.uk) uses.

#### Any data sent over the communicating devices is like
```
<index><value>,<index><value>,<index><value>...

a123,b245,c125...

The total number of characters in the data is predetermined, usually 16 or 32 including the separators.
```

#### Another possible format is without separators
```
<index1><value><index2><value><index3><value>...
```

#### Data format with lowest buffer size
```
<index><value>

Single index value pair
```
This method will have atmost 4 characters per instruction. But given the rate at which movements need to be performed, this process requires higher data transmission rate, so there's the need to juggle with multiple loop timings.
Otherwise fine for slow communication rates.
