module Table = {
  type t =
    Js.t {
      .
      allowMultipleSelection : Js.undefined Js.boolean,
      className : Js.undefined string,
      columnWidths : Js.undefined (Js.Array.t int),
      defaultColumnWidth : Js.undefined int,
      defaultRowHeight : Js.undefined int,
      enableFocus : Js.undefined Js.boolean,
      fillBodyWithGhostCells : Js.undefined Js.boolean,
      focusedCell : Js.undefined Js.Json.t, /*	IFocusedCellCoordinates */
      getCellClipboardData : Js.undefined (int => int => string),
      isColumnReorderable : Js.undefined Js.boolean,
      isColumnResizable : Js.undefined Js.boolean,
      isRowHeaderShown : Js.undefined Js.boolean,
      isRowReorderable : Js.undefined Js.boolean,
      isRowResizable : Js.undefined Js.boolean,
      loadingOptions : Js.undefined (Js.Array.t Js.Json.t), /*	TableLoadingOption[]*/
      maxColumnWidth : Js.undefined int,
      maxRowHeight : Js.undefined int,
      minColumnWidth : Js.undefined int,
      minRowHeight : Js.undefined int,
      numRows : Js.undefined int,
      onColumnWidthChanged : Js.undefined Js.Json.t, /*	IIndexedResizeCallback*/
      onColumnsReordered : Js.undefined (int => int => int => unit),
      onCopy : Js.undefined (Js.boolean => unit),
      onFocus :
        Js.undefined (Js.Json.t => unit), /*	(focusedCell: IFocusedCellCoordinates) => void*/
      onRowHeightChanged : Js.undefined Js.Json.t, /*	IIndexedResizeCallback*/
      onRowsReordered : Js.undefined (int => int => int => unit),
      onSelection :
        Js.undefined (array Js.Json.t => unit), /*	(selectedRegions: IRegion[]) => void*/
      onVisibleCellsChange :
        Js.undefined (
          Js.Json.t => Js.Json.t => unit
        ), /*	(rowIndices: IRowIndices, columnIndices: IColumnIndices) => void*/
      renderBodyContextMenu : Js.undefined Js.Json.t, /*	IContextMenuRenderer*/
      renderRowHeader : Js.undefined Js.Json.t, /*	IRowHeaderRenderer*/
      rowHeights : Js.undefined (Js.Array.t int),
      selectedRegionTransform : Js.undefined Js.Json.t, /*	ISelectedRegionTransform*/
      selectedRegions : Js.undefined (array Js.Json.t), /*	IRegion[]*/
      selectionModes : Js.undefined (array Js.Json.t), /*	RegionCardinality[] */
      styledRegionGroups : Js.undefined (array Js.Json.t) /*	IStyledRegionGroup[]*/
    };
  external reactClass : ReasonReact.reactClass = "Table" [@@bs.module "@blueprintjs/table"];
  /*
   TODO
   http://blueprintjs.com/docs/#core/components/tree.instance-methods
   */
  let make
      ::allowMultipleSelection=?
      ::className=?
      ::columnWidths=?
      ::defaultColumnWidth=?
      ::defaultRowHeight=?
      ::enableFocus=?
      ::fillBodyWithGhostCells=?
      ::focusedCell=?
      ::getCellClipboardData=?
      ::isColumnReorderable=?
      ::isColumnResizable=?
      ::isRowHeaderShown=?
      ::isRowReorderable=?
      ::isRowResizable=?
      ::loadingOptions=?
      ::maxColumnWidth=?
      ::maxRowHeight=?
      ::minColumnWidth=?
      ::minRowHeight=?
      ::numRows=?
      ::onColumnWidthChanged=?
      ::onColumnsReordered=?
      ::onCopy=?
      ::onFocus=?
      ::onRowHeightChanged=?
      ::onRowsReordered=?
      ::onSelection=?
      ::onVisibleCellsChange=?
      ::renderBodyContextMenu=?
      ::renderRowHeader=?
      ::rowHeights=?
      ::selectedRegionTransform=?
      ::selectedRegions=?
      ::selectionModes=?
      ::styledRegionGroups=?
      children /*	ReactElement<IColumnProps> | ReactElement<IColumnProps>[] */ =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "allowMultipleSelection": allowMultipleSelection |> Blueprintjs.unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "columnWidths": columnWidths |> Blueprintjs.unwrapList,
          "defaultColumnWidth": defaultColumnWidth |> Js.Undefined.from_opt,
          "defaultRowHeight": defaultRowHeight |> Js.Undefined.from_opt,
          "enableFocus": enableFocus |> Blueprintjs.unwrapBool,
          "fillBodyWithGhostCells": fillBodyWithGhostCells |> Js.Undefined.from_opt,
          "focusedCell": focusedCell |> Js.Undefined.from_opt,
          "getCellClipboardData": getCellClipboardData |> Js.Undefined.from_opt,
          "isColumnReorderable": isColumnReorderable |> Blueprintjs.unwrapBool,
          "isColumnResizable": isColumnResizable |> Blueprintjs.unwrapBool,
          "isRowHeaderShown": isRowHeaderShown |> Blueprintjs.unwrapBool,
          "isRowReorderable": isRowReorderable |> Blueprintjs.unwrapBool,
          "isRowResizable": isRowResizable |> Blueprintjs.unwrapBool,
          "loadingOptions": loadingOptions |> Blueprintjs.unwrapList,
          "maxColumnWidth": maxColumnWidth |> Js.Undefined.from_opt,
          "maxRowHeight": maxRowHeight |> Js.Undefined.from_opt,
          "minColumnWidth": minColumnWidth |> Js.Undefined.from_opt,
          "minRowHeight": minRowHeight |> Js.Undefined.from_opt,
          "numRows": numRows |> Js.Undefined.from_opt,
          "onColumnWidthChanged": onColumnWidthChanged |> Js.Undefined.from_opt,
          "onColumnsReordered": onColumnsReordered |> Js.Undefined.from_opt,
          "onCopy": onCopy |> Js.Undefined.from_opt,
          "onFocus": onFocus |> Js.Undefined.from_opt,
          "onRowHeightChanged": onRowHeightChanged |> Js.Undefined.from_opt,
          "onRowsReordered": onRowsReordered |> Js.Undefined.from_opt,
          "onSelection": onSelection |> Js.Undefined.from_opt,
          "onVisibleCellsChange": onVisibleCellsChange |> Js.Undefined.from_opt,
          "renderBodyContextMenu": renderBodyContextMenu |> Js.Undefined.from_opt,
          "renderRowHeader": renderRowHeader |> Js.Undefined.from_opt,
          "rowHeights": rowHeights |> Blueprintjs.unwrapList,
          "selectedRegionTransform": selectedRegionTransform |> Js.Undefined.from_opt,
          "selectedRegions": selectedRegions |> Js.Undefined.from_opt,
          "selectionModes": selectionModes |> Js.Undefined.from_opt,
          "styledRegionGroups": styledRegionGroups |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Column = {
  external column : ReasonReact.reactClass = "Column" [@@bs.module "@blueprintjs/table"];
  let make
      name::(name: string)
      renderCell::(renderCell: int => int => ReasonReact.reactElement)
      children =>
    ReasonReact.wrapJsForReason
      reactClass::column props::{"name": name, "renderCell": renderCell} children;
};

module Cell = {
  external cell : ReasonReact.reactClass = "Cell" [@@bs.module "@blueprintjs/table"];
  let make ::text children =>
    ReasonReact.wrapJsForReason reactClass::cell props::{"text": text} children;
};