import java.util.ArrayList;
import java.util.Scanner;


public class GramschmidtOrgBasis{
    
    public static double factor4vector(double array1[], double array2[], int size) {
        double yu1 = 0;
        double u1u1 = 0;
        for (int i = 0; i < size; i++) {
            yu1 += (array1[i] * array2[i]);
        }
        for (int i = 0; i < size; i++) {
            u1u1 += (array2[i] * array2[i]);
        }

        return yu1 / u1u1;

    }

    public static void main(String[] args) {
        ArrayList<double[]> xvectors = new ArrayList<double[]>();
        ArrayList<double[]> vvectors = new ArrayList<double[]>();
        Scanner answer = new Scanner(System.in);
        System.out.println("Input number of vectors");
        int numofV = answer.nextInt();
        System.out.println("Input vector size");
        int size = answer.nextInt();
        double tempx[] = new double[size];
        double tempv[] = new double[size];
        double v1[] = new double[size];

        for (int i = 0; i < numofV; i++) {
            double x[] = new double[size];
            for (int j = 0; j < size; j++) {
                System.out.println("Input x " + (i+1) + " element: " + (j+1));
                x[j] = answer.nextDouble();
                }
            xvectors.add(x);
        }
        answer.close();
        v1 = (double[]) xvectors.get(0);
        vvectors.add(v1);
        for (int i =1; i<numofV; i++)
            {double v[] = new double[size];
            for(int j =0;j<size; j++)
                {v[j] =0;}
                if (i==1)
                    {tempx = (double[]) xvectors.get(i);
                    double xfactor =  factor4vector(tempx, v1, size);
                    for(int j =0;j<size; j++)
                        {v[j] =tempx[j] - (xfactor * v1[j]);}
                    }
                else{
                    tempx = (double[]) xvectors.get(i);
                    for(int j =0;j<size; j++)
                        {v[j] =tempx[j];}
                    for (int j=0; j<i; j++)
                        {tempv = (double[]) vvectors.get(j);
                            double xfactor =  factor4vector(tempx, tempv, size);
                            for(int k =0;k<size; k++)
                            {v[k] -= (xfactor * tempv[k]);}

                        }
                    
                    
                    
                    }

                    
            vvectors.add(v);
            }
            for (int i =0; i<numofV; i++ ) {
                double basis[] = (double[]) vvectors.get(i);
                for (int j=0; j<size; j++)
                    {System.out.print(" " + basis[j]);}
                    System.out.println(" ");
            }
     



    }

}