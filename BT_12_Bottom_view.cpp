  vector<int> ans;
        if(root==NULL){
            return ans;
        }

        map<int, int> m; //mapping of HD and node->data
        queue<pair<Node*, int>> q; //mapping of node and coresponding HD

        //push the root node and its HD for root it is 0
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node*, int> temp=q.front();
            q.pop();

            Node * frontNode=temp.first;
            int hd=temp.second;


            //for 1 to 1 mapping of HD and node
            //if a node is present corresponding to a HD then do nothing
            if(m.find(hd)==m.end()){ //if not present
                m[hd]=frontNode->data;
            }

            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }

        }

        for(auto i:m){
            ans.push_back(i.second); 
        }

        return ans;
