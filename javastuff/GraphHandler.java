import java.awt.Color;
import java.awt.*;
import javax.swing.JPanel;
import java.util.Random;
public class GraphHandler extends JPanel { 
private int vertices[][];
private Graphset graph;
private Graphmosome highest = null;
private twodArray arraycoors;
    
    public GraphHandler(Graphset graph){ 
        vertices = new int[graph.sendSize()][graph.sendSize()];
        this.graph = graph;
        arraycoors = new twodArray(graph.sendSize());
        generategraph();
    }
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        for (int i= 0; i<graph.sendSize();i++)
            {g.setColor(Color.BLACK);
            g.drawRect(vertices[i][0],vertices[i][1], 10, 10);
            g.fillRect(vertices[i][0],vertices[i][1], 10, 10);
             if(highest!=null)
             {for (int j= 0; j< graph.sendSize(); j++)
                    {if(highest.getchromogene(i, j)==1)
                        {
                          g.drawLine(vertices[i][0], vertices[i][1], vertices[j][0], vertices[j][1]);
                          g.drawString(graph.Atposition(i, j), (vertices[i][0] + vertices[j][0])/2, (vertices[i][1] + vertices[j][1])/2);
                        }

                    }
                 

             }
        
    }
    }
    public void generategraph(){
        Random rand = new Random();
        for (int i= 0; i<graph.sendSize();i++)
            {vertices[i][0]= rand.nextInt(700);
            arraycoors.setCoordinates(i, 0, vertices[i][0]);
            vertices[i][1]= rand.nextInt(450);
            arraycoors.setCoordinates(i, 1, vertices[i][1]);
        }
    }
    public void gethighest(Graphmosome gp){
        highest = gp;
    }
public twodArray SendArray(){
    return arraycoors;
}
    }
