//
// Generated by JTB 1.3.1
//

package EDU.purdue.jtb.syntaxtree;

/**
 * Grammar production:
 * f0 -> ( "public" | "protected" | "private" | "static" | "abstract" | "final" | "native" | "synchronized" )*
 * f1 -> ResultType()
 * f2 -> <IDENTIFIER>
 * f3 -> "("
 */
public class MethodDeclarationLookahead implements Node {
   public NodeListOptional f0;
   public ResultType f1;
   public NodeToken f2;
   public NodeToken f3;

   public MethodDeclarationLookahead(NodeListOptional n0, ResultType n1, NodeToken n2, NodeToken n3) {
      f0 = n0;
      f1 = n1;
      f2 = n2;
      f3 = n3;
   }

   public MethodDeclarationLookahead(NodeListOptional n0, ResultType n1, NodeToken n2) {
      f0 = n0;
      f1 = n1;
      f2 = n2;
      f3 = new NodeToken("(");
   }

   public void accept(EDU.purdue.jtb.visitor.Visitor v) {
      v.visit(this);
   }
   public <R,A> R accept(EDU.purdue.jtb.visitor.GJVisitor<R,A> v, A argu) {
      return v.visit(this,argu);
   }
   public <R> R accept(EDU.purdue.jtb.visitor.GJNoArguVisitor<R> v) {
      return v.visit(this);
   }
   public <A> void accept(EDU.purdue.jtb.visitor.GJVoidVisitor<A> v, A argu) {
      v.visit(this,argu);
   }
}

