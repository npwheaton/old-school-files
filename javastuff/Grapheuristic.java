import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

public class Grapheuristic {
    private int chromo[][];
    private int fitness;
    private int size;
    private ArrayList<String> distinctlabels;
    private Boolean visited[];
    private Graphset graph;

    public Grapheuristic(Graphset g){
    graph = g;
    size = g.sendSize();
    chromo = new int[size][size];
    visited = new Boolean[size];
    distinctlabels = new ArrayList<String>();
    blankchromosome();
    initializecheckarray();
    }
    public void blankchromosome(){
    for (int i= 0; i<size; i++)
        {for (int j =0; j<size; j++)
            {chromo[i][j]= 0;}
        }
    }

    public void calcfitness(){
        for (int i= 0; i<size; i++)
            { for (int j =0; j<size; j++)
                {if(chromo[i][j]==1)
                    {String temp = graph.Atposition(i, j);
                    checklabel(temp);
                    }
                }

            }

    }

    // sends fitness value
    public int sendfitness() {
        calcfitness();
        fitness = distinctlabels.size();
        return fitness;
    }

    public int totalNodesvisited() {
        int temp = 0;
        for (int i = 0; i < size; i++) {
            if (visited[i]) {
                temp++;
            }
        }
        return temp;
    }

    public int countEdges() {
        int temp = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (chromo[i][j] == 1) {
                    temp++;
                }
            }
        }
        return temp;
    }

    public Boolean checklabel(String temp) {
        for (Iterator<String> all = distinctlabels.iterator(); all.hasNext();) {
            String label = (String) all.next();
            if (temp.equals(label)) {
                return false;
            }
        }
        AddLABEL(temp);
        return true;
    }

    public void initializecheckarray() {
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }

    }

    public void makeGraph() {
        int vertex = 0;
        do {
            vertex = makeUnDistinctEdge(vertex);
            if (vertex == -1) {
                break;
            }
        } while (totalNodesvisited() < visited.length);
    }

    public int makeUnDistinctEdge(int vertexstart) {
        visited[vertexstart] = true;
        for (int i = 0; i < size; i++) {
            if (vertexstart != i) {
                String temp = graph.Atposition(vertexstart, i);
                if (checklabel(temp)==false & (countEdges() + 1) == totalNodesvisited() & !visited[i]) {
                    chromo[vertexstart][i] = 1;
                    visited[i] = true;
                    return i;
                }
            }
        }
        return checkForOtherEdge(vertexstart);
    }

    public int checkForOtherEdge(int vertexstart) {
        for (int i = 0; i < visited.length; i++) {
            if (visited[i]) {
                for (int j = 0; j < visited.length; j++) {
                    if (i != j) {
                        String temp = graph.Atposition(i, j);
                        if (checklabel(temp)==false & (countEdges() + 1) == totalNodesvisited() & !visited[j]) {
                            chromo[i][j] = 1;
                            visited[j] = true;
                            return j;
                        }
                    }
                }

            }

        }
        for (int i = 0; i < size; i++) {
            if (vertexstart != i) {
                String temp = graph.Atposition(vertexstart, i);
                if (checklabel(temp)==true & (countEdges() + 1) == totalNodesvisited() & !visited[i])
            {chromo[vertexstart][i]= 1;
            visited[i]= true;
            return i;
            }
        }
    }
return -1;    
}

public int getchromogene(int x, int y){
    return chromo[x][y];
}
public void AddLABEL(String target){
distinctlabels.add(target);
}
public String toString(){
    String temp = "";
        for (int i = 0; i < size; i++) {
            temp+= "\n";
            for (int j = 0; j < size; j++) {
                 {temp+= chromo[i][j];
                }
            }
        }
    return temp;
}
}
