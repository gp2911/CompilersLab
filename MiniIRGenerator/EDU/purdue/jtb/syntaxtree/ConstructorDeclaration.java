//
// Generated by JTB 1.3.1
//

package EDU.purdue.jtb.syntaxtree;

/**
 * Grammar production:
 * f0 -> [ "public" | "protected" | "private" ]
 * f1 -> <IDENTIFIER>
 * f2 -> FormalParameters()
 * f3 -> [ "throws" NameList() ]
 * f4 -> "{"
 * f5 -> [ ExplicitConstructorInvocation() ]
 * f6 -> ( BlockStatement() )*
 * f7 -> "}"
 */
public class ConstructorDeclaration implements Node {
   public NodeOptional f0;
   public NodeToken f1;
   public FormalParameters f2;
   public NodeOptional f3;
   public NodeToken f4;
   public NodeOptional f5;
   public NodeListOptional f6;
   public NodeToken f7;

   public ConstructorDeclaration(NodeOptional n0, NodeToken n1, FormalParameters n2, NodeOptional n3, NodeToken n4, NodeOptional n5, NodeListOptional n6, NodeToken n7) {
      f0 = n0;
      f1 = n1;
      f2 = n2;
      f3 = n3;
      f4 = n4;
      f5 = n5;
      f6 = n6;
      f7 = n7;
   }

   public ConstructorDeclaration(NodeOptional n0, NodeToken n1, FormalParameters n2, NodeOptional n3, NodeOptional n4, NodeListOptional n5) {
      f0 = n0;
      f1 = n1;
      f2 = n2;
      f3 = n3;
      f4 = new NodeToken("{");
      f5 = n4;
      f6 = n5;
      f7 = new NodeToken("}");
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

