(function ($, document, window, undefined) {
    // Handy mapping from geocode result object to usable parts/inputs.
    var part_translation = {
        street: {separator: ' ', parts: ['street_number', 'route']},
        city: {separator: ' ', parts: ['locality', 'administrative_area_level_3']},
        state: {parts: ['administrative_area_level_1']},
        zip: {separator: '-', parts: ['postal_code', 'postal_code_suffix']},
    };

    // Parse the geocoded results into the individual address boxes.
    function parseAutocompletedAddress(o) {
        var orig = o.data('geocode_results'),
            data = {},
            newdata = {};

        // Reorganize the geocoding return for simpler reference.
        $.each(orig.address_components, function (k, i) {
            data[i.types[0]] = i.long_name;
        });
        data.formatted = (('formatted_address' in orig) ? orig.formatted_address : '');
        data.html = (('adr_address' in orig) ? orig.adr_address : '');
        data.name = (('name' in orig) ? orig.name : '');
        console.log(data);

        if (data.html != '') {
            parsed = $("<div>" + data.html + "</div>");
            $('#edit-addr-street').val(parsed.find('.street-address').html());
            $('#edit-addr-city').val(parsed.find('.locality').html());
            $('#edit-addr-state').val(parsed.find('.region').html());
            $('#edit-addr-zip').val(parsed.find('.postal-code').html());
        } else {
            // Iterate through the configured parts and set the input values.
            $.each(part_translation, function (kk, ii) {
                var r = '',
                    sep = ('separator' in ii) ? ii.separator : '',
                    n = '#edit-addr-' + kk;
                for (x in ii.parts) {
                    if (ii.parts[x] in data) {
                        r += ((r == '') ? '' : sep) + data[ii.parts[x]];
                    }
                }
                $(n).val(r);
            });
        }
    }

    // Click handler to switch between autocompleter and manual boxes.
    $(document).on('click', '.autocomplete-manual-switch', function (e) {
        $(e.target).closest('.form-item-autocompleter')
            .hide()
            .closest('.form-item-address')
            .find('.manual-entry-container')
            .show();
    });

    // Use the geocoding options to limit autocompletion to US addresses.
    // TODO: This should really be abstracted into Drupal settings.
    var options = {componentRestrictions: {country: 'US'}};

    // Initialize the autocompletion plugin for all marked elements.
    $('.nys-autocompleter').geocomplete(options)
        .bind("geocode:result", function (event, result) {
            parseAutocompletedAddress($(this).data('geocode_results', result));
            $('.autocomplete-manual-switch').trigger('click');
        });

    // Google's scripts set the autocomplete attribute to "off", which
    // is promptly ignored by even their own browser.  Reset the attr
    // to something sufficiently random to kill concurrent display.
    $('.nys-autocompleter').on('focus', function(e) {
        if (e.target.attributes['autocomplete'].value.substr(0,2) !== 'f-') {
            $(e.target).attr('autocomplete', 'f-' + Math.random().toString(16).substring(2));
        }
    });

})(jQuery, document, window);
