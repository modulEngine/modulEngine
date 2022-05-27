# Structure
```
ComponentGroup1 > Component1 > entityID + data
                > Component2 > entityID + data
                > Component3 > entityID + data
                
ComponentGroup2 > Component4 > entityID + data
                > Component5 > entityID + data
                > Component6 > entityID + data
                
ComponentGroup3 > Component7 > entityID + data
                > Component8 > entityID + data
                > Component9 > entityID + data
               
System > ComponentSet1 > ComponentRef1 > Component1
                       > ComponentRef2 > Component4
                       > ComponentRef3 > Component7
                       
       > ComponentSet2 > ComponentRef4 > Component2
                       > ComponentRef5 > Component5
                       > ComponentRef6 > Component8
                       
       > ComponentSet3 > ComponentRef7 > Component3
                       > ComponentRef8 > Component6
                       > ComponentRef9 > Component9
```

## Internal Managing Systems
### entityManager
- keeps track of IDs that can be used for entities.

### ComponentManager
- creates and removes components
- each component gets added to a componentGroup of its type
- a component exists of the ID of the "owning" entity and the data in it

### SystemManager
- handles the creation of systems
- every time an entity has a component added it checks if a system has a component requirement that gets fulfilled
  - if so add the entities components to said system
- a system can have componentTypes it does not allow
  - this means that if an entity gains a component that is "excluded" by a system the componentSet that belongs to that entity gets removed
- a system has a list of componentSets, these contain references to components that all belong to the same entity
