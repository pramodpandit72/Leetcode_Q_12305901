public int helper(Node root, int depth) {
    if (root.children == null) return depth;

    int max = Integer.MIN_VALUE;
    for (Node child : root.children) {
        max = Math.max(max, helper(child, depth + 1));
    }

    return max;
}