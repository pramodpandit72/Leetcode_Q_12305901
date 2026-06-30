public boolean uniqueOccurrences(int[] arr) {
    return Arrays.stream(arr).distinct().count() != arr.length;  
}