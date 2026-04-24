import java.util.*;

class Solution {
    public int maxPoints(int[][] points) {
        if (points.length <= 2) return points.length;
        int max = 0;

        for (int i = 0; i < points.length; i++) {
            Map<String, Integer> map = new HashMap<>();
            int overlap = 0;
            int currMax = 0;

            for (int j = i + 1; j < points.length; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 == x2 && y1 == y2) {
                    overlap++;
                    continue;
                }

                int dx = x2 - x1;
                int dy = y2 - y1;
                int gcd = gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;

                String key = dx + "/" + dy;
                map.put(key, map.getOrDefault(key, 0) + 1);
                currMax = Math.max(currMax, map.get(key));
            }

            max = Math.max(max, currMax + overlap + 1);
        }

        return max;
    }

    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
