//
// Generated by JTB 1.3.2
//

package syntaxtree;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 * Grammar production:
 * f0 -> NoOpStmt()
 *       | ErrorStmt()
 *       | CJumpStmt()
 *       | JumpStmt()
 *       | HStoreStmt()
 *       | HLoadStmt()
 *       | MoveStmt()
 *       | PrintStmt()
 */
public class Stmt implements Node {
   public NodeChoice f0;
    public Set<Temp> liveIn;
    public Set<Temp> liveOut;
    public Set<Temp> tempsDef;
    public Set<Temp> tempsUsed;
    public Set<Stmt> successors;
   public int stmtIndex;
    public boolean isJmp;
    public boolean isCJmp;
    public Label conditionalSuccessor;
   public Stmt(NodeChoice n0) {
      f0 = n0;
       liveIn = new HashSet<Temp>();
       liveOut = new HashSet<Temp>();
       tempsDef = new HashSet<Temp>();
       tempsUsed = new HashSet<Temp>();
       successors = new HashSet<Stmt>();
       conditionalSuccessor = null;
       stmtIndex = 0;
       isJmp = false;
       isCJmp = false;
   }
    public  Stmt(){
        f0 = null;
        liveIn = new HashSet<Temp>();
        liveOut = new HashSet<Temp>();
        tempsDef = new HashSet<Temp>();
        tempsUsed = new HashSet<Temp>();
        successors = new HashSet<Stmt>();
        conditionalSuccessor = null;
        stmtIndex = 0;
        isJmp = false;
    }

    public String toString(){
        if(f0 != null)
            return f0.choice.toString();
        else
            return "return stmt";
    }

   public void accept(visitor.Visitor v) {
      v.visit(this);
   }
   public <R,A> R accept(visitor.GJVisitor<R,A> v, A argu) {
      return v.visit(this,argu);
   }
   public <R> R accept(visitor.GJNoArguVisitor<R> v) {
      return v.visit(this);
   }
   public <A> void accept(visitor.GJVoidVisitor<A> v, A argu) {
      v.visit(this,argu);
   }
}

