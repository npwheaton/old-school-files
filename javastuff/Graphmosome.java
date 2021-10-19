
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;


public class Graphmosome {
    private int chromo[][];
    private int fitness;
    private double Mchance = 0.0;
    private double Cchance = 0.0;
    private int size;
    private LinkedList<String> distinctlabels = new LinkedList<String>();
    private Boolean visited[];
    private Boolean connected = false;
    private Boolean cycles = true;
    private Graphset graph;
 
 //constructor used for initial population
public Graphmosome( Graphset graph){
    this.graph = graph;
    this.size = this.graph.sendSize();
    chromo = new int[size][size];
    visited = new Boolean[size];
    blankchromosome();
    populatechromo();
    initializecheckarray();
    }
 //constructor used Graphmosomes made from crossover
 public Graphmosome(double chance,double Cchance, Graphset graph){
     Mchance = chance;
     this.Cchance = Cchance;
     this.graph = graph;
     this.size = this.graph.sendSize();
     chromo = new int[size][size];
     visited = new Boolean[size];
     blankchromosome();
     initializecheckarray();
     }

 //used in 2 point crossover, inherit half of the sets from each parent
 public void inheritance(Graphmosome dad, Graphmosome mom){
    Random rand = new Random();
     double temp;
     int temp2 = 0;
     //roll to see if you can Crossbreed the Graphmosome
     temp = rand.nextDouble();
     if (temp<Cchance)
        {
        for (int i= 0; i<size; i++)
            {for (int j =0; j<size; j++)
                {if (dad.getchromogene(i,j) == mom.getchromogene(i,j))
                        {
                        chromo[i][j]= dad.getchromogene(i,j);
                        }
                else {if (i==j)
                        {chromo[i][j] = 0;}
                    else{
                        temp = rand.nextInt(2);
                        if (temp2 == 0)
                            {chromo[i][j] = temp2;
                            chromo[j][i] = temp2;  
                            }
                        else
                            {chromo[i][j] = temp2;
                            chromo[j][i] = 0;
                            }
                        
                
                        }   
                     }   
                }
            }
    
        }
    else
     populatechromo();
 }
 
 public void mutate(){
     Random rand = new Random();
     double temp;
     int temp2;
     int xpos;
     int ypos;
     //roll to see if you can mutate the Graphmosome
     temp = rand.nextDouble();
     if (temp<Mchance)
         {//mutate set and the corresponding position so there is at most one edge between any two nodes
         do{
            xpos = rand.nextInt(size);
            ypos = rand.nextInt(size);
         }while (xpos==ypos);
         temp2 = rand.nextInt(2);
         if (temp2 == 0)
             {chromo[xpos][ypos] = temp2;
              chromo[ypos][xpos] = temp2;  
             }
         else
             {chromo[xpos][ypos] = temp2;
                chromo[ypos][xpos] = 0; 
             }
                
         }

     }
   
 //finds the fitness
 public void calcfitness(){
    for (int i= 0; i<size; i++)
        { for (int j =0; j<size; j++)
            {if(chromo[i][j]==1)
                {String temp = graph.Atposition(i, j);
                checkdistinctlabel(temp);
                }
            }
     }
     fitness = distinctlabels.size();
   }
 //sends fitness value
 public int sendfitness(){ 
     calcfitness();
     return fitness;}

public Boolean isConnected(){
    initializecheckarray();
    dfs(0, 0);
    if(totalNodesvisited()==visited.length)
    {connected = true;}
    else
    {connected = false;}
    return connected;
}
public Boolean HasCycle(){
    if(countEdges()==(size-1))
        {cycles = false;}
    else
        {cycles = true;}
    return cycles;
}

public void dfs(int v, int edgev){
    visited[v] = true;
    if(totalNodesvisited()==visited.length)
        {}
    else if(edgev<countEdges())
    {for (int j =0; j<size; j++) 
    {if(chromo[v][j]==1 & !visited[j])
        {edgev++;
        dfs(j,edgev);
        }
    else if(chromo[j][v]==1 & !visited[j])
            {edgev++;
            dfs(j, edgev);}
        }
    }

}

public int totalNodesvisited(){
    int temp = 0;
    for (int i=0; i<size; i++)
        {if(visited[i])
            {temp++;}
        }
return temp;
}
public  int countEdges(){
    int temp = 0;
    for (int i= 0; i<size; i++)
    {for (int j =0; j<size; j++)
        {if(chromo[i][j]==1)
            {temp++;}
        }
    }
return temp;
}

//makes the sets unique if for some reason its not.
 public Boolean checkdistinctlabel(String temp){
    for (Iterator<String> all = distinctlabels.iterator(); all.hasNext(); ) {
     String label = (String) all.next();
     if (temp.equals(label))
        {return false;}
     }
    distinctlabels.add(temp);
    return true;
    }
//populates the Graphmosome sets
public void populatechromo(){
    Random rand = new Random();
    int temp = 0;
    for (int i= 0; i<size; i++)
        {for (int j =0; j<size; j++)
            {if (chromo[j][i]!=1 & (i!=j))
                {temp = rand.nextInt(2);
                chromo[i][j] = temp;
                }
                 
            }
        }
}

public void initializecheckarray(){
    for (int i =0; i<size; i++)
        { visited[i] = false;}

}
public int getchromogene(int x, int y){
    return chromo[x][y];
}
public void blankchromosome(){
    for (int i= 0; i<size; i++)
    { for (int j =0; j<size; j++)
        {chromo[i][j]= 0;}
    }
}
public void snakeseed(){
    blankchromosome();
        for (int i= 0; i<size-1; i++)
        {chromo[i][i+1] =1;}
}
public void spiderwebseed(){
    blankchromosome();
        for (int i= 0; i<size-1; i++)
        {chromo[0][i+1] =1;}
}
public void bintreeseed(){
    blankchromosome();
        chromo[0][1]= 1;
        for (int i= 0; i<size-2; i++)
        {chromo[i][i+2] =1;}
}

public String toString(){
    String temp = "";
    for (int i= 0; i<size; i++)
        { for (int j =0; j<size; j++)
            {temp +=chromo[i][j]+ " ";}
        }
    return temp;
}
}
 
