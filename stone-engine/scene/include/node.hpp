// Copyright: Stone-Engine

#pragma once

#include "object.hpp"
#include <vector>
#include <functional>

namespace STN
{

    namespace Scene
    {

        class Node : public Object
        {
        public:
            Node();
            Node(const Node &other);

            virtual ~Node();

            void addChild(std::shared_ptr<Node> child);
            void removeChild(std::shared_ptr<Node> child);

            std::shared_ptr<Node> getParent() const;
            const std::vector<std::shared_ptr<Node>> &getChildren() const;

            virtual void forEachChild(std::function<void(std::shared_ptr<Node>)> callback) const;

            virtual void update(float deltaTime);
            virtual void render();

        private:
            std::vector<std::shared_ptr<Node>> _children;
            std::weak_ptr<Node> _parent;
        };

    } // namespace Scene

} // namespace STN
