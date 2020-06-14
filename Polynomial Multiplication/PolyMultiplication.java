import java.util.Arrays;

public class PolyMultiplication {

    // Naive Algorithm;
    public static void main(String args[]) {
        int n = 3;
        int[] A = {3, 2, 5};
        int[] B = {5, 1, 2};

        int[] product = new int[2*n - 1];

        Arrays.fill(product, 0);
        for(int i = 0; i <= n - 1; i++) {
            for(int j = 0; j <= n - 1; j++) {
                product[i + j] = product[i + j] + (A[i] * B[j]);
            }
        }
        for(int x : product) {
            System.out.print(x + " ");
        }
        System.out.println();
    } 
}