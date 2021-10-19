import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
public class GraphEvolDisplay extends JFrame {
    private JPanel rightbar;
    private JTextArea gen;
    private JTextArea high;
    private JTextArea avg;
    private BorderLayout b;
    private GraphHandler gh;
    private HeurGraphDisplay hgd;
        
    public GraphEvolDisplay(Graphset graph){
        super("Minimum Label Spanning tree Evolutionary Alorithm");
        b = new BorderLayout();
       setLayout(b);
       pack();
       rightbar = new JPanel();
       gen = new JTextArea();
       high = new JTextArea();
       avg = new JTextArea();
       gh = new GraphHandler(graph);
       hgd = new HeurGraphDisplay(graph);
       gen.setEditable(false);
       high.setEditable(false);
       avg.setEditable(false);
       add(rightbar, b.SOUTH);
       add(gh,b.CENTER);
       rightbar.setLayout(new BoxLayout(rightbar, BoxLayout.Y_AXIS));
       rightbar.add(gen);
       rightbar.add(high);
       rightbar.add(avg);
       gen.setText("Generations: ");
       high.setText("Highest Fitness: ");
       avg.setText("Average Fitness: ");
       hgd.Send2dArray(gh.SendArray());
       setSize(800, 600);
       setVisible(true);
       setLocationRelativeTo(null);
       addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent event) {
          System.exit(0);
        }
      });
    }
  

  public void endstats( int High, int AVG, Graphmosome hghest, int i, int generations, Grapheuristic heur){
    gh.gethighest(hghest);
    hgd.SendHeur(heur);
    hgd.stats(heur.sendfitness(), heur);
    String temp = "Generation: \n" + i;
    gen.setText(temp);
    String temp2 = "Highest Fitness: \n" + High;
    high.setText(temp2);
    String temp3 = "Average Fitness: \n" + AVG;
    avg.setText(temp3);
    gh.repaint();
    }
}