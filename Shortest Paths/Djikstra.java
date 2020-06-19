/**
 * Dijkstra algorithm is Greedy Algorithm,
 * Complexity - O(VlogV)
*/




import java.util.Arrays;
public class Djikstra {
    private static final int vertices = 9;

    public int minDistance(int[] distances, boolean[] visited) {
        int miniDistance = Integer.MAX_VALUE;
        int min_index = -1;

        for(int i = 0; i < vertices; i++) {
            if(visited[i] == false && distances[i] <= miniDistance) {
                miniDistance = distances[i];
                min_index = i;
            }
        }
        return min_index;
    }

    public void shortestPath(int[][] graph, int source) {
        boolean[] visited = new boolean[vertices];
        Arrays.fill(visited, false);
        int[] distances = new int[vertices];
        Arrays.fill(distances, Integer.MAX_VALUE);

        distances[source] = 0;

        for(int i = 0; i < (vertices - 1); i++) {
            int u = minDistance(distances, visited);
            visited[u] = true;



            for(int j = 0; j < vertices; j++) {
                if(!visited[j] && graph[u][j] != 0 && distances[u] != Integer.MAX_VALUE && graph[u][j] + distances[u] < distances[j]) {
                    distances[j] = distances[u] + graph[u][j];
                }
            }
        }
        printGraph(distances);
    }

    public void printGraph(int[] distances) {
        System.out.println("Result of Djiksrta SP: ");
        for(int i = 0; i < vertices; i++) {
            System.out.println(i + " --> " + distances[i]);
        }
        
    }

    public static void main(String args[]) {
        int[][] graph = new int [][] {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

        Djikstra object = new Djikstra();
        object.shortestPath(graph, 0);
    }
}