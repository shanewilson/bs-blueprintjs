module DatePickerModifiers = {
  type t = Js.Dict.t (Js.Date.t => Js.boolean);
};

module TimePickerPrecision = {
  type t =
    | MINUTE
    | SECOND
    | MILLISECOND;
};

module DateRange = {
  type t = (Js.Date.t, Js.Date.t);
};

module DateRangeBoundary = {
  type t =
    | START
    | END;
};

module DateRangeShortCut = {
  type t = Js.Json.t;
};

module DateRangeShortCuts = {
  type t =
    | Boolean Js.boolean
    | DateRangeShortCuts (array DateRangeShortCut.t);
};

module DatePicker = {
  type t =
    Js.t {
      .
      canClearSelection : Js.undefined Js.boolean,
      className : Js.undefined string,
      closeOnSelection : Js.undefined Js.boolean,
      defaultValue : Js.undefined Js.Date.t,
      disabled : Js.undefined Js.boolean,
      format : Js.undefined string,
      initialMonth : Js.undefined Js.Date.t,
      inputProps : Js.undefined Js.Json.t, /* HTMLProps<HTMLInputElement> & IInputGroupProps */
      invalidDateMessage : Js.undefined string,
      locale : Js.undefined string,
      localeUtils : Js.undefined Js.Json.t, /* DayPicker.LocaleUtils */
      maxDate : Js.undefined Js.Date.t,
      minDate : Js.undefined Js.Date.t,
      modifiers : Js.undefined DatePickerModifiers.t,
      onChange : Js.undefined (Js.Date.t => unit),
      onError : Js.undefined (Js.Date.t => unit),
      outOfRangeMessage : Js.undefined string,
      popoverProps : Js.undefined Blueprintjs.Popover.t,
      rightElement : Js.undefined ReasonReact.reactElement,
      timePrecision : Js.undefined TimePickerPrecision.t,
      value : Js.undefined Js.Date.t
    };
  external reactClass : ReasonReact.reactClass =
    "DatePicker" [@@bs.module "@blueprintjs/datetime"];
  let make
      ::canClearSelection=?
      ::className=?
      ::closeOnSelection=?
      ::defaultValue=?
      ::disabled=?
      ::format=?
      ::initialMonth=?
      ::inputProps=?
      ::invalidDateMessage=?
      ::locale=?
      ::localeUtils=?
      ::maxDate=?
      ::minDate=?
      ::modifiers=?
      ::onChange=?
      ::onError=?
      ::outOfRangeMessage=?
      ::popoverProps=?
      ::rightElement=?
      ::timePrecision=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "canClearSelection": canClearSelection |> Blueprintjs.unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "closeOnSelection": closeOnSelection |> Blueprintjs.unwrapBool,
          "defaultValue": defaultValue |> Js.Undefined.from_opt,
          "disabled": disabled |> Blueprintjs.unwrapBool,
          "format": format |> Js.Undefined.from_opt,
          "initialMonth": initialMonth |> Js.Undefined.from_opt,
          "inputProps": inputProps |> Js.Undefined.from_opt,
          "invalidDateMessage": invalidDateMessage |> Js.Undefined.from_opt,
          "locale": locale |> Js.Undefined.from_opt,
          "localeUtils": localeUtils |> Js.Undefined.from_opt,
          "maxDate": maxDate |> Js.Undefined.from_opt,
          "minDate": minDate |> Js.Undefined.from_opt,
          "modifiers": modifiers |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "onError": onError |> Js.Undefined.from_opt,
          "outOfRangeMessage": outOfRangeMessage |> Js.Undefined.from_opt,
          "popoverProps": popoverProps |> Js.Undefined.from_opt,
          "rightElement": rightElement |> Js.Undefined.from_opt,
          "timePrecision": timePrecision |> Js.Undefined.from_opt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module DateRangePicker = {
  type t =
    Js.t {
      .
      allowSingleDayRange : Js.undefined Js.boolean,
      boundaryToModify : Js.undefined DateRangeBoundary.t,
      className : Js.undefined string,
      contiguousCalendarMonths : Js.undefined Js.boolean,
      defaultValue : Js.undefined DateRange.t,
      initialMonth : Js.undefined Js.Date.t,
      locale : Js.undefined string,
      localeUtils : Js.undefined Js.Json.t, /* 	DayPicker.LocaleUtils */
      maxDate : Js.undefined Js.Date.t,
      minDate : Js.undefined Js.Date.t,
      modifiers : Js.undefined DatePickerModifiers.t,
      onChange : Js.undefined (Js.Date.t => unit),
      onHoverChange : Js.undefined (Js.Date.t => unit),
      shortcuts : Js.undefined DateRangeShortCuts.t,
      value : Js.undefined DateRange.t
    };
  external reactClass : ReasonReact.reactClass =
    "DateRangePicker" [@@bs.module "@blueprintjs/datetime"];
  let make
      ::allowSingleDayRange=?
      ::boundaryToModify=?
      ::className=?
      ::contiguousCalendarMonths=?
      ::defaultValue=?
      ::initialMonth=?
      ::locale=?
      ::localeUtils=?
      ::maxDate=?
      ::minDate=?
      ::modifiers=?
      ::onChange=?
      ::onHoverChange=?
      ::shortcuts=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "allowSingleDayRange": allowSingleDayRange |> Blueprintjs.unwrapBool,
          "boundaryToModify": boundaryToModify |> Js.Undefined.from_opt,
          "className": className |> Js.Undefined.from_opt,
          "contiguousCalendarMonths": contiguousCalendarMonths |> Blueprintjs.unwrapBool,
          "defaultValue": defaultValue |> Js.Undefined.from_opt,
          "initialMonth": initialMonth |> Js.Undefined.from_opt,
          "locale": locale |> Js.Undefined.from_opt,
          "localeUtils": localeUtils |> Js.Undefined.from_opt,
          "maxDate": maxDate |> Js.Undefined.from_opt,
          "minDate": minDate |> Js.Undefined.from_opt,
          "modifiers": modifiers |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "onHoverChange": onHoverChange |> Js.Undefined.from_opt,
          "shortcuts": shortcuts |> Js.Undefined.from_opt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module TimePicker = {
  type t =
    Js.t {
      .
      className : Js.undefined string,
      defaultValue : Js.undefined Js.Date.t,
      disabled : Js.undefined Js.boolean,
      maxDate : Js.undefined Js.Date.t,
      minDate : Js.undefined Js.Date.t,
      onChange : Js.undefined (Js.Date.t => unit),
      precision : Js.undefined TimePickerPrecision.t,
      selectAllOnFocus : Js.undefined Js.boolean,
      showArrowButtons : Js.undefined Js.boolean,
      value : Js.undefined Js.Date.t
    };
  external reactClass : ReasonReact.reactClass =
    "TimePicker" [@@bs.module "@blueprintjs/datetime"];
  let make
      ::className=?
      ::defaultValue=?
      ::disabled=?
      ::maxDate=?
      ::minDate=?
      ::onChange=?
      ::precision=?
      ::selectAllOnFocus=?
      ::showArrowButtons=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "className": className |> Js.Undefined.from_opt,
          "defaultValue": defaultValue |> Js.Undefined.from_opt,
          "disabled": disabled |> Blueprintjs.unwrapBool,
          "maxDate": maxDate |> Js.Undefined.from_opt,
          "minDate": minDate |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "precision": precision |> Js.Undefined.from_opt,
          "selectAllOnFocus": selectAllOnFocus |> Blueprintjs.unwrapBool,
          "showArrowButtons": showArrowButtons |> Blueprintjs.unwrapBool,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module DateTimePicker = {
  type t =
    Js.t {
      .
      canClearSelection : Js.undefined Js.boolean,
      className : Js.undefined string,
      datePickerProps : Js.undefined DatePicker.t,
      defaultValue : Js.undefined Js.Date.t,
      onChange : Js.undefined (Js.Date.t => unit),
      timePickerProps : Js.undefined TimePicker.t,
      value : Js.undefined Js.Date.t
    };
  external reactClass : ReasonReact.reactClass =
    "DateTimePicker" [@@bs.module "@blueprintjs/datetime"];
  let make
      ::canClearSelection=?
      ::className=?
      ::datePickerProps=?
      ::defaultValue=?
      ::onChange=?
      ::timePickerProps=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "canClearSelection": canClearSelection |> Blueprintjs.unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "datePickerProps": datePickerProps |> Js.Undefined.from_opt,
          "defaultValue": defaultValue |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "timePickerProps": timePickerProps |> Js.Undefined.from_opt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module DateInput = {
  type t =
    Js.t {
      .
      canClearSelection : Js.undefined Js.boolean,
      className : Js.undefined string,
      defaultValue : Js.undefined Js.Date.t,
      initialMonth : Js.undefined Js.Date.t,
      locale : Js.undefined string,
      localeUtils : Js.undefined Js.Json.t, /* 	DayPicker.LocaleUtils */
      maxDate : Js.undefined Js.Date.t,
      minDate : Js.undefined Js.Date.t,
      modifiers : Js.undefined DatePickerModifiers.t,
      onChange : Js.undefined (Js.Date.t => unit),
      showActionsBar : Js.undefined Js.boolean,
      value : Js.undefined Js.Date.t
    };
  external reactClass : ReasonReact.reactClass = "DateInput" [@@bs.module "@blueprintjs/datetime"];
  let make
      ::canClearSelection=?
      ::className=?
      ::defaultValue=?
      ::initialMonth=?
      ::locale=?
      ::localeUtils=?
      ::maxDate=?
      ::minDate=?
      ::modifiers=?
      ::onChange=?
      ::showActionsBar=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "canClearSelection": canClearSelection |> Blueprintjs.unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "defaultValue": defaultValue |> Js.Undefined.from_opt,
          "initialMonth": initialMonth |> Js.Undefined.from_opt,
          "locale": locale |> Js.Undefined.from_opt,
          "localeUtils": localeUtils |> Js.Undefined.from_opt,
          "maxDate": maxDate |> Js.Undefined.from_opt,
          "minDate": minDate |> Js.Undefined.from_opt,
          "modifiers": modifiers |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "showActionsBar": showActionsBar |> Blueprintjs.unwrapBool,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};

module DateRangeInput = {
  type t =
    Js.t {
      .
      allowSingleDayRange : Js.undefined Js.boolean,
      className : Js.undefined string,
      closeOnSelection : Js.undefined Js.boolean,
      contiguousCalendarMonths : Js.undefined Js.boolean,
      defaultValue : Js.undefined DateRange.t,
      disabled : Js.undefined Js.boolean,
      endInputProps : Js.undefined Js.Json.t, /* HTMLProps<HTMLInputElement> & IInputGroupProps */
      format : Js.undefined string,
      initialMonth : Js.undefined Js.Date.t,
      invalidDateMessage : Js.undefined string,
      locale : Js.undefined string,
      localeUtils : Js.undefined Js.Json.t, /* 	DayPicker.LocaleUtils */
      maxDate : Js.undefined Js.Date.t,
      minDate : Js.undefined Js.Date.t,
      modifiers : Js.undefined DatePickerModifiers.t,
      onChange : Js.undefined (DateRange.t => unit),
      onError : Js.undefined (DateRange.t => unit),
      outOfRangeMessage : Js.undefined string,
      overlappingDatesMessage : Js.undefined string,
      popoverProps : Js.undefined Blueprintjs.Popover.t,
      selectAllOnFocus : Js.undefined Js.boolean,
      shortcuts : Js.undefined DateRangeShortCuts.t,
      startInputProps :
        Js.undefined Js.Json.t, /* HTMLProps<HTMLInputElement> & IInputGroupProps */
      value : Js.undefined DateRange.t
    };
  external reactClass : ReasonReact.reactClass =
    "DateRangeInput" [@@bs.module "@blueprintjs/datetime"];
  let make
      ::allowSingleDayRange=?
      ::className=?
      ::closeOnSelection=?
      ::contiguousCalendarMonths=?
      ::defaultValue=?
      ::disabled=?
      ::endInputProps=?
      ::format=?
      ::initialMonth=?
      ::invalidDateMessage=?
      ::locale=?
      ::localeUtils=?
      ::maxDate=?
      ::minDate=?
      ::modifiers=?
      ::onChange=?
      ::onError=?
      ::outOfRangeMessage=?
      ::overlappingDatesMessage=?
      ::popoverProps=?
      ::selectAllOnFocus=?
      ::shortcuts=?
      ::startInputProps=?
      ::value=?
      children =>
    ReasonReact.wrapJsForReason
      ::reactClass
      props::(
        {
          "allowSingleDayRange": allowSingleDayRange |> Blueprintjs.unwrapBool,
          "className": className |> Js.Undefined.from_opt,
          "closeOnSelection": closeOnSelection |> Blueprintjs.unwrapBool,
          "contiguousCalendarMonths": contiguousCalendarMonths |> Blueprintjs.unwrapBool,
          "defaultValue": defaultValue |> Js.Undefined.from_opt,
          "disabled": disabled |> Blueprintjs.unwrapBool,
          "endInputProps": endInputProps |> Js.Undefined.from_opt,
          "format": format |> Js.Undefined.from_opt,
          "initialMonth": initialMonth |> Js.Undefined.from_opt,
          "invalidDateMessage": invalidDateMessage |> Js.Undefined.from_opt,
          "locale": locale |> Js.Undefined.from_opt,
          "localeUtils": localeUtils |> Js.Undefined.from_opt,
          "maxDate": maxDate |> Js.Undefined.from_opt,
          "minDate": minDate |> Js.Undefined.from_opt,
          "modifiers": modifiers |> Js.Undefined.from_opt,
          "onChange": onChange |> Js.Undefined.from_opt,
          "onError": onError |> Js.Undefined.from_opt,
          "outOfRangeMessage": outOfRangeMessage |> Js.Undefined.from_opt,
          "overlappingDatesMessage": overlappingDatesMessage |> Js.Undefined.from_opt,
          "popoverProps": popoverProps |> Js.Undefined.from_opt,
          "selectAllOnFocus": selectAllOnFocus |> Blueprintjs.unwrapBool,
          "shortcuts": shortcuts |> Js.Undefined.from_opt,
          "startInputProps": startInputProps |> Js.Undefined.from_opt,
          "value": value |> Js.Undefined.from_opt
        }: t
      )
      children;
};