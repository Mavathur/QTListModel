# QTListModel

 It is the QT-Qml application designed to show nested List view by delegating one custom model with another custom model. 
 Collection of Albums of songs is used to demonstrate this. Initially a combobox is used to render the Album Items. These Album Items as a list are held by Album List which is handled By Album Model.
 AlbumModel is a QAbstract List Model. Each member of the combobox is again a combobox. This holds the SongItems as a list which are handled by SongModel.
 This SongModel is a QAbstractListModel. Items of the SongModel are finally as the last stage of Hierarchy redered using Items are rendered using a TextFieldItem.
 This provides a good realisation for nested List like view. Using the RowLayout the playButton and the Slider for the volume are provided. The functionalities are yet to be realised. 
 Two Custom QAbstractListModels are used for this purpose. Buttons are provided to add and delete the songs or the albums from the list.
 A role "expandable" is unused in the model. This role can be used to delete selected songs/albums, which is realized using a check state of checkbox.
 Items can be dynamically added and removedwhich is handled using C++.
