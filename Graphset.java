import java.util.Random;

public class Graphset{
    private int size;
    private String gset[][];
    private String labels[];
    
    public Graphset(int Nsize){
        labels = new String[]{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U","V","W", "X","Y", "Z"};
        size = Nsize;
        gset = new String[size][size];
        for (int i= 0; i<size; i++)
            {for (int j =0; j<size; j++)
                {gset[i][j]= "";}
            }
        }
    public void populateSet(){
        Random rand = new Random();
        int temp = 0;
        for (int i= 0; i<size; i++)
            {for (int j =0; j<size; j++)
                {if (i==j)
                    {gset[i][j]= "";}
                else if (gset[j][i]!= "")
                    {gset[i][j]= gset[j][i];}
                else
                    {if(size>labels.length)
                        {temp = rand.nextInt(labels.length);
                        gset[i][j] = labels[temp];
                        }
                    else
                        temp = rand.nextInt(size);
                        gset[i][j] = labels[temp];
                    }
                }
            }
        }
    public String Atposition(int x, int y){
            return gset[x][y];
        }
    public int sendSize(){
        return size;
        }
    public String toString(){
        String temp = "";
        for(int i = 0; i<gset.length; i++){
            temp+= gset[i]+ " ";
            }
        return temp;
        }
    }