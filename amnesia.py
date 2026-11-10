from collections import OrderedDict
import json
import sys


def replay(capacity, operations):
    cache = OrderedDict()
    results = []
    for kind, key, *payload in operations:
        if kind == "get":
            results.append(cache.get(key))
        elif capacity:
            if len(cache) >= capacity:
                cache.popitem(last=False)
            cache[key] = payload[0]
            cache.move_to_end(key)
    return results


data = json.load(sys.stdin)
print(json.dumps(replay(data["capacity"], data["operations"])))
