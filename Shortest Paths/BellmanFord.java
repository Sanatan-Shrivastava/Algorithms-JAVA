/**
 * Number of iterations = vertices - 1;
 * Algorithm used in BF - DProgramming
 * Comolexity: O(V*E) -- O(n^2);
 * 
*/
import java.util.Arrays;
import java.util.Scanner;

public class BellmanFord {

    class Edge {
        int source, dest, weight;

        Edge() {
            source = 0;
            dest = 0;
            weight = 0;
        }
    };

    static int V, E;
    Edge edge[];

    BellmanFord(int v, int e) {
        V = v;
        E = e;
        edge = new Edge[e];
        for(int i = 0; i < e; i++) {
            edge[i] = new Edge();
        }
    }

    public void bellmanFord(BellmanFord graph, int source) {
        int V = BellmanFord.V;
        int E = BellmanFord.E;
        int[] distances = new int[V];
        boolean[] visited = new boolean[V];
        Arrays.fill(distances, Integer.MAX_VALUE);
        Arrays.fill(visited, false);

        distances[source] = 0;
        for(int e = 0; e < V; e++) {
            for(int i = 0; i < E; i++) {
                int u = graph.edge[i].source;
                int v = graph.edge[i].dest;
                int weight = graph.edge[i].weight;
                if(distances[u] != Integer.MAX_VALUE && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
        for(int j = 0; j < E; j++) {
            int u = graph.edge[j].source;
            int v = graph.edge[j].dest;
            int weight = graph.edge[j].weight;
            if(distances[u] != Integer.MAX_VALUE && distances[u] + weight < distances[v]) {
                System.out.println("Negative Cycle exists!");
                return;
            }
        }

        distPrint(distances, V);
    }



    public void distPrint(int[] distances, int V) {
        System.out.println("Bellman Ford SP: ");
        for(int i = 0; i < V; i++) {
            System.out.println(i + " --> " + distances[i]);
        }
    }



    public static void main(String args[]) {
        System.out.println("Enter V: ");
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        System.out.println("Enter E: ");
        int E = sc.nextInt();
        BellmanFord graph = new BellmanFord(V, E);
        System.out.println("Enter source : destination : weight ");
        for(int i = 0; i < E; i++) {
            graph.edge[i].source = sc.nextInt();
            graph.edge[i].dest = sc.nextInt();
            graph.edge[i].weight = sc.nextInt();
        }
        graph.bellmanFord(graph, 0);
    }
}