# Search Comparison Table

The department names are stored in sorted order:

```text
Backend, CEO, Development, Finance,
Frontend, HR, IT, Testing
```

## Execution Results

| Search Target | Linear Search Comparisons | Binary Search Comparisons | Result |
|---|---:|---:|---|
| CEO | 2 | 3 | Found |
| Frontend | 5 | 2 | Found |
| Testing | 8 | 4 | Found |

## Analysis

### CEO

Linear search finds `CEO` at the second position, so it requires two comparisons.

Binary search requires three comparisons for this particular array and midpoint calculation.

### Frontend

Linear search requires five comparisons because `Frontend` is the fifth element.

Binary search requires only two comparisons.

### Testing

Linear search requires eight comparisons because `Testing` is the last element.

Binary search requires four comparisons.

## Comparison

| Feature | Linear Search | Binary Search |
|---|---|---|
| Data arrangement | Sorted or unsorted | Must be sorted |
| Best-case time | O(1) | O(1) |
| Average-case time | O(n) | O(log n) |
| Worst-case time | O(n) | O(log n) |
| Extra space | O(1) | O(1) |
| Suitable for frequent searches | Less suitable | More suitable |
| Suitable for small unsorted data | Suitable | Not suitable until sorted |

## Conclusion from Results

For the given small department list, the number of comparisons varies according to the search target.

Linear search performs well when the target is near the beginning.

Binary search is more suitable for large sorted lists or when many searches are performed because its worst-case time complexity is O(log n).
