module Select (Item: {type t;}) => {
  type t 'a =
    Js.t {
      .
      className : Js.undefined string,
      filterable : Js.undefined Js.boolean,
      inputProps : Js.undefined Js.Json.t, /* IInputGroupProps & HTMLProps<HTMLInputElement> */
      itemListPredicate : Js.undefined (string => list 'a => 'a),
      itemPredicate : Js.undefined (string => 'a => int => Js.boolean),
      itemRenderer :
        Js.undefined (
          Js.Json.t => ReasonReact.reactElement
        ), /* (itemProps: ISelectItemRendererProps<T>) => JSX.Element */
      items : list 'a,
      noResults : Js.undefined ReasonReact.reactElement,
      onItemSelect :
        Js.undefined (
          'a => ReactEventRe.Synthetic.t => unit
        ), /*(item: T, event?: SyntheticEvent<HTMLElement>) => void */
      popoverProps : Js.undefined Blueprintjs.Popover.t,
      resetOnClose : Js.undefined Js.boolean,
      resetOnSelect : Js.undefined Js.boolean
    };
  external reactClass : ReasonReact.reactClass = "Select" [@@bs.module "@blueprintjs/labs"];
  let make
      ::className=?
      ::filterable=?
      ::inputProps=?
      ::itemListPredicate=?
      ::itemPredicate=?
      ::itemRenderer=?
      ::items
      ::noResults=?
      ::onItemSelect=?
      ::popoverProps=?
      ::resetOnClose=?
      ::resetOnSelect=?
      children /*	ReactElement<IColumnProps> | ReactElement<IColumnProps>[] */ =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "filterable": filterable |> Js.Undefined.from_opt,
          "inputProps": inputProps |> Js.Undefined.from_opt,
          "itemListPredicate": itemListPredicate |> Js.Undefined.from_opt,
          "itemPredicate": itemPredicate |> Js.Undefined.from_opt,
          "itemRenderer": itemRenderer |> Js.Undefined.from_opt,
          "items": items,
          "noResults": noResults |> Js.Undefined.from_opt,
          "onItemSelect": onItemSelect |> Js.Undefined.from_opt,
          "popoverProps": popoverProps |> Js.Undefined.from_opt,
          "resetOnClose": resetOnClose |> Js.Undefined.from_opt,
          "resetOnSelect": resetOnSelect |> Js.Undefined.from_opt
        }:
          t Item.t
      )
      children;
};