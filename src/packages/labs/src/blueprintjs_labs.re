module SelectItemRenderer = {
  type t 'a = Js.t {. handleClick : string, index : int, isActive : Js.boolean, item : 'a};
};

module Select (Item: {type t;}) => {
  type t 'a =
    Js.t {
      .
      className : Js.undefined string,
      filterable : Js.undefined Js.boolean,
      inputProps : Js.undefined Js.Json.t, /* IInputGroupProps & HTMLProps<HTMLInputElement> */
      itemListPredicate : Js.undefined (string => array 'a => array 'a),
      itemPredicate : Js.undefined (string => 'a => int => Js.boolean),
      itemRenderer : SelectItemRenderer.t 'a => ReasonReact.reactElement,
      items : array 'a,
      noResults : Js.undefined ReasonReact.reactElement,
      onItemSelect : 'a => ReactEventRe.Synthetic.t => unit,
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
      ::itemRenderer
      ::items
      ::noResults=?
      ::onItemSelect
      ::popoverProps=?
      ::resetOnClose=?
      ::resetOnSelect=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "filterable": filterable |> Blueprintjs.unwrapBool,
          "inputProps": inputProps |> Js.Undefined.from_opt,
          "itemListPredicate": itemListPredicate |> Js.Undefined.from_opt,
          "itemPredicate": itemPredicate |> Js.Undefined.from_opt,
          "itemRenderer": itemRenderer,
          "items": items,
          "noResults": noResults |> Blueprintjs.unwrapJSX,
          "onItemSelect": onItemSelect,
          "popoverProps": popoverProps |> Js.Undefined.from_opt,
          "resetOnClose": resetOnClose |> Blueprintjs.unwrapBool,
          "resetOnSelect": resetOnSelect |> Blueprintjs.unwrapBool
        }:
          t Item.t
      )
      children;
};

module Suggest (Item: {type t;}) => {
  type t 'a =
    Js.t {
      .
      className : Js.undefined string,
      closeOnSelect : Js.undefined Js.boolean,
      inputProps : Js.undefined Js.Json.t, /* IInputGroupProps & HTMLProps<HTMLInputElement> */
      inputValueRenderer : 'a => string,
      itemListPredicate : Js.undefined (string => array 'a => array 'a),
      itemPredicate : Js.undefined (string => 'a => int => Js.boolean),
      itemRenderer : SelectItemRenderer.t 'a => ReasonReact.reactElement,
      items : array 'a,
      noResults : Js.undefined ReasonReact.reactElement,
      onItemSelect : 'a => ReactEventRe.Synthetic.t => unit,
      openOnKeyDown : Js.undefined Js.boolean,
      popoverProps : Js.undefined Blueprintjs.Popover.t
    };
  external reactClass : ReasonReact.reactClass = "Suggest" [@@bs.module "@blueprintjs/labs"];
  let make
      ::className=?
      ::closeOnSelect=?
      ::inputProps=?
      ::inputValueRenderer
      ::itemListPredicate=?
      ::itemPredicate=?
      ::itemRenderer
      ::items
      ::noResults=?
      ::onItemSelect
      ::openOnKeyDown=?
      ::popoverProps=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "closeOnSelect": closeOnSelect |> Blueprintjs.unwrapBool,
          "inputProps": inputProps |> Js.Undefined.from_opt,
          "inputValueRenderer": inputValueRenderer,
          "itemListPredicate": itemListPredicate |> Js.Undefined.from_opt,
          "itemPredicate": itemPredicate |> Js.Undefined.from_opt,
          "itemRenderer": itemRenderer,
          "items": items,
          "noResults": noResults |> Blueprintjs.unwrapJSX,
          "onItemSelect": onItemSelect,
          "openOnKeyDown": openOnKeyDown |> Blueprintjs.unwrapBool,
          "popoverProps": popoverProps |> Js.Undefined.from_opt
        }:
          t Item.t
      )
      children;
};

module MultiSelect (Item: {type t;}) => {
  type t 'a =
    Js.t {
      .
      className : Js.undefined string,
      itemListPredicate : Js.undefined (string => array 'a => array 'a),
      itemPredicate : Js.undefined (string => 'a => int => Js.boolean),
      itemRenderer : SelectItemRenderer.t 'a => ReasonReact.reactElement,
      items : array 'a,
      noResults : Js.undefined ReasonReact.reactElement,
      onItemSelect : 'a => ReactEventRe.Synthetic.t => unit,
      openOnKeyDown : Js.undefined Js.boolean,
      popoverProps : Js.undefined Blueprintjs.Popover.t,
      resetOnSelect : Js.undefined Js.boolean,
      selectedItems : Js.undefined (array 'a),
      tagInputProps : Js.undefined Js.Json.t,
      tagRenderer : SelectItemRenderer.t 'a => ReasonReact.reactElement
    };
  external reactClass : ReasonReact.reactClass = "MultiSelect" [@@bs.module "@blueprintjs/labs"];
  let make
      ::className=?
      ::itemListPredicate=?
      ::itemPredicate=?
      ::itemRenderer
      ::items
      ::noResults=?
      ::onItemSelect
      ::openOnKeyDown=?
      ::popoverProps=?
      ::resetOnSelect=?
      ::selectedItems=?
      ::tagInputProps=?
      ::tagRenderer
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "itemListPredicate": itemListPredicate |> Js.Undefined.from_opt,
          "itemPredicate": itemPredicate |> Js.Undefined.from_opt,
          "itemRenderer": itemRenderer,
          "items": items,
          "noResults": noResults |> Blueprintjs.unwrapJSX,
          "onItemSelect": onItemSelect,
          "openOnKeyDown": openOnKeyDown |> Blueprintjs.unwrapBool,
          "popoverProps": popoverProps |> Js.Undefined.from_opt,
          "resetOnSelect": resetOnSelect |> Blueprintjs.unwrapBool,
          "selectedItems": selectedItems |> Js.Undefined.from_opt,
          "tagInputProps": tagInputProps |> Js.Undefined.from_opt,
          "tagRenderer": tagRenderer
        }:
          t Item.t
      )
      children;
};

module Omnibox (Item: {type t;}) => {
  type t 'a =
    Js.t {
      .
      className : Js.undefined string,
      inputProps : Js.undefined Js.Json.t, /* IInputGroupProps & HTMLProps<HTMLInputElement> */
      isOpen : Js.boolean,
      itemListPredicate : Js.undefined (string => array 'a => array 'a),
      itemPredicate : Js.undefined (string => 'a => int => Js.boolean),
      itemRenderer : SelectItemRenderer.t 'a => ReasonReact.reactElement,
      items : array 'a,
      noResults : Js.undefined ReasonReact.reactElement,
      onClose : Js.undefined (ReactEventRe.Synthetic.t => unit),
      onItemSelect : 'a => ReactEventRe.Synthetic.t => unit,
      overlayProps : Js.undefined Blueprintjs.Overlay.t,
      resetOnSelect : Js.undefined Js.boolean
    };
  external reactClass : ReasonReact.reactClass = "Omnibox" [@@bs.module "@blueprintjs/labs"];
  let make
      ::className=?
      ::inputProps=?
      ::isOpen
      ::itemListPredicate=?
      ::itemPredicate=?
      ::itemRenderer
      ::items
      ::noResults=?
      ::onClose=?
      ::onItemSelect
      ::overlayProps=?
      ::resetOnSelect=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "inputProps": inputProps |> Js.Undefined.from_opt,
          "isOpen": isOpen |> Js.Boolean.to_js_boolean,
          "itemListPredicate": itemListPredicate |> Js.Undefined.from_opt,
          "itemPredicate": itemPredicate |> Js.Undefined.from_opt,
          "itemRenderer": itemRenderer,
          "items": items,
          "noResults": noResults |> Blueprintjs.unwrapJSX,
          "onClose": onClose |> Js.Undefined.from_opt,
          "onItemSelect": onItemSelect,
          "overlayProps": overlayProps |> Js.Undefined.from_opt,
          "resetOnSelect": resetOnSelect |> Blueprintjs.unwrapBool
        }:
          t Item.t
      )
      children;
};

module QueryListRenderer = {
  type t 'a =
    Js.t {
      .
      activeItem : 'a,
      className : Js.undefined string,
      filteredItems : array 'a,
      handleItemSelect : 'a => ReactEventRe.Synthetic.t => unit,
      handleKeyDown : ReactEventRe.Keyboard.t,
      handleKeyUp : ReactEventRe.Keyboard.t,
      items : array 'a,
      itemsParentRef : Dom.element => unit,
      query : string
    };
};

module QueryList (Item: {type t;}) => {
  type t 'a =
    Js.t {
      .
      activeItem : 'a,
      className : Js.undefined string,
      itemListPredicate : Js.undefined (string => array 'a => array 'a),
      itemPredicate : Js.undefined (string => 'a => int => Js.boolean),
      items : array 'a,
      onActiveItemChange : 'a => unit,
      onItemSelect : 'a => ReactEventRe.Synthetic.t => unit,
      onKeyDown : Js.undefined ReactEventRe.Keyboard.t,
      onKeyUp : Js.undefined ReactEventRe.Keyboard.t,
      query : string,
      renderer : QueryListRenderer.t 'a => ReasonReact.reactElement
    };
  external reactClass : ReasonReact.reactClass = "QueryList" [@@bs.module "@blueprintjs/labs"];
  let make
      ::activeItem
      ::className=?
      ::itemListPredicate=?
      ::itemPredicate=?
      ::items
      ::onActiveItemChange
      ::onItemSelect
      ::onKeyDown=?
      ::onKeyUp=?
      ::query
      ::renderer
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "activeItem": activeItem,
          "className": className |> Js.Undefined.from_opt,
          "itemListPredicate": itemListPredicate |> Js.Undefined.from_opt,
          "itemPredicate": itemPredicate |> Js.Undefined.from_opt,
          "items": items,
          "onActiveItemChange": onActiveItemChange,
          "onItemSelect": onItemSelect,
          "onKeyDown": onKeyDown |> Js.Undefined.from_opt,
          "onKeyUp": onKeyUp |> Js.Undefined.from_opt,
          "query": query,
          "renderer": renderer
        }:
          t Item.t
      )
      children;
};

module TagInput = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      inputProps : Js.undefined Js.Json.t, /* React.HTMLProps<HTMLInputElement> */
      leftIconName : Js.undefined string, /* IconName */
      onAdd : Js.undefined (array string => Js.boolean),
      onChange : Js.undefined (array string => Js.boolean),
      onRemove : Js.undefined (string => int => unit),
      placeholder : Js.undefined string,
      rightElement : Js.undefined ReasonReact.reactElement,
      separator : Js.undefined string, /* string | false | RegExp"," */
      tagProps :
        Js.undefined Js.Json.t, /* ITagProps | ((value: ReactNode, index: number) => ITagProps) */
      values : array ReasonReact.reactElement
    };
  external reactClass : ReasonReact.reactClass = "TagInput" [@@bs.module "@blueprintjs/labs"];
  let make
      ::className=?
      ::inputProps=?
      ::leftIconName=?
      ::onAdd=?
      ::onChange=?
      ::onRemove=?
      ::placeholder=?
      ::rightElement=?
      ::separator=?
      ::tagProps=?
      ::values
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "inputProps": inputProps |> Js.Undefined.from_opt,
          "leftIconName": leftIconName |> Js.Undefined.from_opt,
          "onAdd": onAdd |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "onRemove": onRemove |> Js.Undefined.from_opt,
          "placeholder": placeholder |> Js.Undefined.from_opt,
          "rightElement": rightElement |> Blueprintjs.unwrapJSX,
          "separator": separator |> Js.Undefined.from_opt,
          "tagProps": tagProps |> Js.Undefined.from_opt,
          "values": values
        }: t
      )
      children;
};

module Placement = {
  type t =
    | AUTO
    | TOP
    | RIGHT
    | BOTTOM
    | LEFT;
  let toString x =>
    switch x {
    | AUTO => "auto"
    | TOP => "top"
    | RIGHT => "right"
    | BOTTOM => "bottom"
    | LEFT => "left"
    };
  let fromOpt o =>
    switch o {
    | None => Js.Undefined.empty
    | Some x => Js.Undefined.return (toString x)
    };
};

module Popover2 = {
  type t =
    Js.t {
      .
      autoFocus : Js.undefined Js.boolean,
      backdropProps : Js.undefined ReactDOMRe.reactDOMProps,
      canEscapeKeyClose : Js.undefined Js.boolean,
      className : Js.undefined string,
      content : Js.undefined ReasonReact.reactElement,
      defaultIsOpen : Js.undefined Js.boolean,
      disabled : Js.undefined Js.boolean,
      enforceFocus : Js.undefined Js.boolean,
      hasBackdrop : Js.undefined Js.boolean,
      hoverCloseDelay : Js.undefined int,
      hoverOpenDelay : Js.undefined int,
      inheritDarkTheme : Js.undefined Js.boolean,
      inline : Js.undefined Js.boolean,
      interactionKind : Js.undefined Js.boolean,
      isOpen : Js.undefined Js.boolean,
      _lazy : Js.undefined Js.boolean,
      minimal : Js.undefined Js.boolean,
      modifiers : Js.undefined Js.Json.t, /* Modifiers */
      onClose : Js.undefined (ReactEventRe.Synthetic.t => unit),
      onInteraction : Js.undefined (Js.boolean => unit),
      openOnTargetFocus : Js.undefined Js.boolean,
      placement : Js.undefined string,
      popoverClassName : Js.undefined string,
      popoverDidOpen : Js.undefined (unit => unit),
      popoverWillClose : Js.undefined (unit => unit),
      popoverWillOpen : Js.undefined (unit => unit),
      portalClassName : Js.undefined string,
      rootElementTag : Js.undefined string,
      target : Js.undefined ReasonReact.reactElement,
      transitionDuration : Js.undefined int
    };
  external reactClass : ReasonReact.reactClass = "Popover2" [@@bs.module "@blueprintjs/core"];
  let make
      ::autoFocus=?
      ::backdropProps=?
      ::canEscapeKeyClose=?
      ::className=?
      ::content=?
      ::defaultIsOpen=?
      ::disabled=?
      ::enforceFocus=?
      ::hasBackdrop=?
      ::hoverCloseDelay=?
      ::hoverOpenDelay=?
      ::inheritDarkTheme=?
      ::inline=?
      ::interactionKind=?
      ::isOpen=?
      ::_lazy=?
      ::minimal=?
      ::modifiers=?
      ::onClose=?
      ::onInteraction=?
      ::openOnTargetFocus=?
      ::placement=?
      ::popoverClassName=?
      ::popoverDidOpen=?
      ::popoverWillClose=?
      ::popoverWillOpen=?
      ::portalClassName=?
      ::rootElementTag=?
      ::target=?
      ::transitionDuration=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "autoFocus": autoFocus |> Blueprintjs.unwrapBool,
          "backdropProps": backdropProps |> Js.Undefined.from_opt,
          "canEscapeKeyClose": canEscapeKeyClose |> Blueprintjs.unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "content": content |> Blueprintjs.unwrapJSX,
          "defaultIsOpen": defaultIsOpen |> Blueprintjs.unwrapBool,
          "disabled": disabled |> Blueprintjs.unwrapBool,
          "enforceFocus": enforceFocus |> Blueprintjs.unwrapBool,
          "hasBackdrop": hasBackdrop |> Blueprintjs.unwrapBool,
          "hoverCloseDelay": hoverCloseDelay |> Js.Undefined.from_opt,
          "hoverOpenDelay": hoverOpenDelay |> Js.Undefined.from_opt,
          "inheritDarkTheme": inheritDarkTheme |> Blueprintjs.unwrapBool,
          "inline": inline |> Blueprintjs.unwrapBool,
          "interactionKind": interactionKind |> Js.Undefined.from_opt,
          "isOpen": isOpen |> Blueprintjs.unwrapBool,
          "_lazy": _lazy |> Blueprintjs.unwrapBool,
          "minimal": minimal |> Blueprintjs.unwrapBool,
          "modifiers": modifiers |> Js.Undefined.from_opt,
          "onClose": onClose |> Js.Undefined.from_opt,
          "onInteraction": onInteraction |> Js.Undefined.from_opt,
          "openOnTargetFocus": openOnTargetFocus |> Blueprintjs.unwrapBool,
          "placement": placement |> Placement.fromOpt,
          "popoverClassName": popoverClassName |> Js.Undefined.from_opt,
          "popoverDidOpen": popoverDidOpen |> Js.Undefined.from_opt,
          "popoverWillClose": popoverWillClose |> Js.Undefined.from_opt,
          "popoverWillOpen": popoverWillOpen |> Js.Undefined.from_opt,
          "portalClassName": portalClassName |> Js.Undefined.from_opt,
          "rootElementTag": rootElementTag |> Js.Undefined.from_opt,
          "target": target |> Blueprintjs.unwrapJSX,
          "transitionDuration": transitionDuration |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module Tooltip2 = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      content : ReasonReact.reactElement,
      defaultIsOpen : Js.undefined Js.boolean,
      disabled : Js.undefined Js.boolean,
      hoverCloseDelay : Js.undefined int,
      hoverOpenDelay : Js.undefined int,
      inheritDarkTheme : Js.undefined Js.boolean,
      inline : Js.undefined Js.boolean,
      intent : Js.undefined int,
      isOpen : Js.undefined Js.boolean,
      modifiers : Js.undefined Js.Json.t, /* Modifiers */
      onInteraction : Js.undefined (Js.boolean => unit),
      openOnTargetFocus : Js.undefined Js.boolean,
      placement : Js.undefined string,
      portalClassName : Js.undefined string,
      rootElementTag : Js.undefined string,
      tooltipClassName : Js.undefined string,
      transitionDuration : Js.undefined int
    };
  external reactClass : ReasonReact.reactClass = "Popover2" [@@bs.module "@blueprintjs/core"];
  let make
      ::className=?
      ::content
      ::defaultIsOpen=?
      ::disabled=?
      ::hoverCloseDelay=?
      ::hoverOpenDelay=?
      ::inheritDarkTheme=?
      ::inline=?
      ::intent=?
      ::isOpen=?
      ::modifiers=?
      ::onInteraction=?
      ::openOnTargetFocus=?
      ::placement=?
      ::portalClassName=?
      ::rootElementTag=?
      ::tooltipClassName=?
      ::transitionDuration=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "content": content (),
          "defaultIsOpen": defaultIsOpen |> Blueprintjs.unwrapBool,
          "disabled": disabled |> Blueprintjs.unwrapBool,
          "hoverCloseDelay": hoverCloseDelay |> Js.Undefined.from_opt,
          "hoverOpenDelay": hoverOpenDelay |> Js.Undefined.from_opt,
          "inheritDarkTheme": inheritDarkTheme |> Blueprintjs.unwrapBool,
          "inline": inline |> Blueprintjs.unwrapBool,
          "intent": intent |> Blueprintjs.Intent.fromOpt,
          "isOpen": isOpen |> Blueprintjs.unwrapBool,
          "modifiers": modifiers |> Js.Undefined.from_opt,
          "onInteraction": onInteraction |> Js.Undefined.from_opt,
          "openOnTargetFocus": openOnTargetFocus |> Blueprintjs.unwrapBool,
          "placement": placement |> Placement.fromOpt,
          "portalClassName": portalClassName |> Js.Undefined.from_opt,
          "rootElementTag": rootElementTag |> Js.Undefined.from_opt,
          "tooltipClassName": tooltipClassName |> Js.Undefined.from_opt,
          "transitionDuration": transitionDuration |> Js.Undefined.from_opt
        }: t
      )
      children;
};