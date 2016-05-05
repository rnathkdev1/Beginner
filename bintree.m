classdef bintree <handle
    
    
    properties
        data
    end
    
    properties(SetAccess=private)
        right=bintree.empty;
        left=bintree.empty;
        
    end
    
    methods
        
        function node=bintree(data)
            if nargin>0
                node.data=data;
            end
        end
        
        function addnodes(head)
            
            
            left1=bintree(2);
            head.left=left1;
            
            right1=bintree(3);
            head.right=right1;
            
            right2=bintree(7);
            right1.right=right2;
            
            left2=bintree(6);
            right1.left=left2;
            
            right3=bintree(5);
            left1.right=right3;
            
            left3=bintree(4);
            left1.left=left3;
            
        end
            
        function inorder(node)
            if (isempty(node))
                %disp(strcat(['empty: '],int2str(node.data)))
                return;
            end
            
            inorder(node.left);
            disp(node.data);
            inorder(node.right);
            
        end
            
    end
end