Converted from Array of Structures (AoS) to Structure of Arrays (SoA), more cache-friendly data structure.

### Setup

```bash
cd "3. metrics/python"
python3 metrics.py
```

### Before

```python
class User(object):
    def __init__(self, user_id, name, age, address, payments):
        ...

def average_age(users):
    for u in users.values():
        total += u.age
```

### After

```python
class Data:
    def __init__(self):
        self.ages = []
        self.payment_amounts = []

def average_age(data):
    return sum(data.ages) / len(data.ages)
```

### Performance comparison

```
-----------------------------------------------------
| Metric         | Original | Optimized | Speedup   |
-----------------------------------------------------
| Data Loading   | 5.494s   | 1.451s    | 3.79x     |
-----------------------------------------------------
| Computation    | 2.183s   | 0.217s    | 10.07x    |
-----------------------------------------------------
| Total          | 7.676s   | 1.668s    | 4.60x     |
-----------------------------------------------------
```
